/*
 * Copyright 2014-present IVK JSC. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BROKER_BROKER_H
#define BROKER_BROKER_H

#include <atomic>
#include <memory>
#include <string>
#include <unordered_map>
#include <Poco/ThreadPool.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Net/StreamSocket.h>
#include "AsyncLogger.h"
#include "ThreadeSafeLogStream.h"
#include "BlockingConcurrentQueueHeader.h"
#include "Configuration.h"
#include "MessageDataContainer.h"
#include "Singleton.h"

#include <Poco/Condition.h>
#include <Poco/RWLock.h>
#include <Poco/Thread.h>
#include <FixedSizeUnorderedMap.h>

namespace upmq {
namespace broker {

class Connection;
class AsyncTCPHandler;
class Consumer;
class Exchange;

class Broker {
 public:
  using ConnectionsList = FSUnorderedMap<std::string, std::unique_ptr<Connection>>;
  std::unique_ptr<ThreadSafeLogStream> logStream;

 private:
  std::string _id;
  Exchange &_exchange;
  ConnectionsList _connections;
  std::atomic_bool _isRunning;
  std::atomic_bool _isReadable;
  std::atomic_bool _isWritable;
  Poco::ThreadPool _readablePool;
  Poco::ThreadPool _writablePool;
  std::unique_ptr<Poco::RunnableAdapter<Broker>> _readbleAdapter;
  std::unique_ptr<Poco::RunnableAdapter<Broker>> _writableAdapter;
  using BQ = moodycamel::ConcurrentQueue<std::pair<std::string, size_t>>;
  using BQIndexes = moodycamel::BlockingConcurrentQueue<size_t>;
  mutable std::vector<BQIndexes> _readableIndexes;
  mutable std::vector<BQIndexes> _writableIndexes;
  std::atomic_size_t _readableIndexCounter{0};
  std::atomic_size_t _writableIndexCounter{0};
  enum { BUFFER_SIZE = 65536 };

 public:
  explicit Broker(std::string id, Exchange &exchange);
  virtual ~Broker();
  const std::string &id() const;
  void onEvent(const AsyncTCPHandler &ahandler, MessageDataContainer &sMessage);

  void onConnect(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onSetClientId(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onDisconnect(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onCreateSession(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onCloseSession(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onBegin(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onCommit(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onAbort(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onMessage(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onSender(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onUnsender(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onSubscription(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onSubscribe(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onUnsubscribe(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onUnsubscription(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  static void onAcknowledge(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onBrowser(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onDestination(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);
  void onUndestination(const AsyncTCPHandler &tcpHandler, const MessageDataContainer &sMessage, MessageDataContainer &outMessage);

  void removeTcpConnection(const std::string &clientID, size_t tcpConnectionNum);
  void removeTcpConnection(Connection &connection, size_t tcpConnectionNum);
  void removeConsumers(const std::string &destinationID, const std::string &subscriptionID, size_t tcpNum);
  bool isConnectionExists(const std::string &clientID);
  std::string currentTransaction(const std::string &clientID, const std::string &sessionID) const;

  void eraseConnection(const std::string &connectionID);

  void start();
  void stop();
  void onReadable();
  void onWritable();
  bool read(size_t num);
  bool write(size_t num);
  void putReadable(size_t queueNum, size_t num);
  void putWritable(size_t queueNum, size_t num);
  size_t connectionsSize() const;
  Exchange &exchange() const;

 private:
  static void rwput(std::atomic_bool &isValid, BQIndexes &bqIndex, size_t num);
};
}  // namespace broker
}  // namespace upmq

typedef Singleton<upmq::broker::Broker> BROKER;

#endif  // BROKER_BROKER_H
