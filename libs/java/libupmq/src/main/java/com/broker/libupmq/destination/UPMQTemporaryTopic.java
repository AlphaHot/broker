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
 
package com.broker.libupmq.destination;

import java.util.UUID;

import javax.jms.JMSException;
import javax.jms.TemporaryTopic;

public class UPMQTemporaryTopic extends UPMQDestination implements TemporaryTopic {

	public UPMQTemporaryTopic() {
		super(UPMQDestination.TEMP_TOPIC_PREFIX + UUID.randomUUID().toString());
	}

	public UPMQTemporaryTopic(String name) {
		super(UPMQDestination.TEMP_TOPIC_PREFIX + name);
	}

	@Override
	public String getTopicName() throws JMSException {
		return getUri().substring(TEMP_TOPIC_PREFIX.length());
	}

	@Override
	public void delete() throws JMSException {

	}
}
