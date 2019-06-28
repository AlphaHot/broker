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

#include "SenderState.h"
#include <utility>
using namespace upmq;
using namespace upmq::state;
using namespace decaf::lang;

////////////////////////////////////////////////////////////////////////////////
SenderState::SenderState(Pointer<Command> info) : info(std::move(info)) {}

////////////////////////////////////////////////////////////////////////////////
SenderState::~SenderState() {}

////////////////////////////////////////////////////////////////////////////////
const Pointer<Command> SenderState::getInfo() const { return this->info; }
