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

#include "SubscribeState.h"

using namespace upmq;
using namespace upmq::state;
using namespace decaf::lang;

////////////////////////////////////////////////////////////////////////////////
SubscribeState::SubscribeState(Pointer<Command> info_) : info(std::move(info_)) {}

////////////////////////////////////////////////////////////////////////////////
SubscribeState::~SubscribeState() {}

////////////////////////////////////////////////////////////////////////////////
Pointer<Command> SubscribeState::getInfo() const { return this->info; }
