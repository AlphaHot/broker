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

#ifndef _DECAF_UTIL_CONCURRENT_RUNNABLEFUTURE_H_
#define _DECAF_UTIL_CONCURRENT_RUNNABLEFUTURE_H_

#include <decaf/util/Config.h>

#include <decaf/lang/Runnable.h>
#include <decaf/util/concurrent/Future.h>

namespace decaf {
namespace util {
namespace concurrent {

/**
 * A Runnable version of the Future type.  When the run method has completed
 * successfully the Future will be considered complete and its get method will
 * return the produced result.
 *
 * @since 1.0
 */
template <typename T>
class RunnableFuture : public Future<T>, public decaf::lang::Runnable {
 public:
  virtual ~RunnableFuture() {}
};
}  // namespace concurrent
}  // namespace util
}  // namespace decaf

#endif /* _DECAF_UTIL_CONCURRENT_RUNNABLEFUTURE_H_ */
