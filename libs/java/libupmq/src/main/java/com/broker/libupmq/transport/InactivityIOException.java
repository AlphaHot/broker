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
 
package com.broker.libupmq.transport;

import java.io.IOException;

/**
 * This is exception is thrown when the transport layer detects that the underlying socket has been inactive for too
 * long.
 * 
 * 
 */
public class InactivityIOException extends IOException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 5816001466763503220L;

	public InactivityIOException() {
		super();
	}

	/**
	 * @param message
	 */
	public InactivityIOException(String message) {
		super(message);
	}

}
