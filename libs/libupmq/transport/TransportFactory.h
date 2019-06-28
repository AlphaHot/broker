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

#ifndef _UPMQ_TRANSPORT_FACTORY_H_
#define _UPMQ_TRANSPORT_FACTORY_H_

#include <decaf/lang/Pointer.h>
#include <decaf/net/URI.h>
#include <decaf/util/Properties.h>
#include <transport/Config.h>
#include <transport/Transport.h>
#include <transport/UPMQException.h>

namespace upmq {
namespace transport {

/**
 * Defines the interface for Factories that create Transports or
 * TransportFilters.
 * <p>
 * The factory should be able to create either a completely configured
 * Transport meaning that it has all the appropriate filters wrapping it,
 * or it should be able to create a slimed down version that is used in
 * composite transports like Failover or Fanout.
 *
 * @since 3.0
 */
class UPMQCPP_API TransportFactory {
 public:
  virtual ~TransportFactory() {}

  /**
   * Creates a fully configured Transport instance which could be a chain
   * of filters and transports.
   * @param location - URI location to connect to plus any properties to assign.
   * @throws UPMQexception if an error occurs
   */
  virtual Pointer<Transport> create(const decaf::net::URI &location) = 0;

  /**
   * Creates a slimed down Transport instance which can be used in composite
   * transport instances.
   * @param location - URI location to connect to plus any properties to assign.
   * @throws UPMQexception if an error occurs
   */
  virtual Pointer<Transport> createComposite(const decaf::net::URI &location) = 0;
};
}  // namespace transport
}  // namespace upmq

#endif /*_UPMQ_TRANSPORT_FACTORY_H_*/
