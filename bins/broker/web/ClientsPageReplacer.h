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

#ifndef BROKER_CLIENTSPAGEREPLACER_H
#define BROKER_CLIENTSPAGEREPLACER_H

#include "TemplateParamReplacer.h"

class StorageFactory;
class Storage;
class IStorageSession;

class ClientsPageReplacer : public TemplateParamReplacer {
  std::string _destination;
  int _type;

 public:
  enum ClientsParam { rows = 0 };

  ClientsPageReplacer(std::string pageName, std::string destinationName, int destinationType);

  ~ClientsPageReplacer() override;

  std::string getH1() const override;

  std::string rowsReplacer();
};

#endif  // BROKER_CLIENTSPAGEREPLACER_H
