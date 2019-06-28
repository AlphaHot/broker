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

#ifndef _DECAF_NET_SOCKETERROR_H_
#define _DECAF_NET_SOCKETERROR_H_

#include <decaf/util/Config.h>
#include <string>

namespace decaf {
namespace net {

/**
 * Static utility class to simplify handling of error codes
 * for socket operations.
 */
class DECAF_API SocketError {
 public:
  /**
   * Gets the last error appropriate for the platform.
   */
  static int getErrorCode();

  /**
   * Gets the string description for the last error.
   */
  static std::string getErrorString();
};
}  // namespace net
}  // namespace decaf

#endif /*_DECAF_NET_SOCKETERROR_H_*/
