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

#ifndef _DECAF_LANG_EXCEPTIONS_EXCEPTIONDEFINES_H_
#define _DECAF_LANG_EXCEPTIONS_EXCEPTIONDEFINES_H_

/**
 * Macro for catching and rethrowing an exception of
 * a given type.
 * @param type The type of the exception to throw
 * (e.g. Exception ).
 */
#define DECAF_CATCH_RETHROW(type)   \
  catch (type & ex) {               \
    ex.setMark(__FILE__, __LINE__); \
    throw;                          \
  }

/**
 * Macro for catching an exception of one type and then rethrowing
 * as another type.
 * @param sourceType the type of the exception to be caught.
 * @param targetType the type of the exception to be thrown.
 */
#define DECAF_CATCH_EXCEPTION_CONVERT(sourceType, targetType) \
  catch (sourceType & ex) {                                   \
    targetType aTarget(ex.clone());                           \
    aTarget.setMark(__FILE__, __LINE__);                      \
    throw targetType(std::move(aTarget));                     \
  }

/**
 * A catch-all that throws a known exception.
 * @param type the type of exception to be thrown.
 */
#define DECAF_CATCHALL_THROW(type)                              \
  catch (...) {                                                 \
    throw type(__FILE__, __LINE__, "caught unknown exception"); \
  }

/**
 * A catch-all that does not throw an exception, one use would
 * be to catch any exception in a destructor and mark it, but not
 * throw so that cleanup would continue as normal.
 */
#define DECAF_CATCHALL_NOTHROW()                                                        \
  catch (...) {                                                                         \
    lang::Exception ex(__FILE__, __LINE__, "caught unknown exception, not rethrowing"); \
  }

/**
 * Macro for catching and rethrowing an exception of
 * a given type.
 * @param type The type of the exception to throw
 * (e.g. Exception ).
 */
#define DECAF_CATCH_NOTHROW(type)   \
  catch (type & ex) {               \
    ex.setMark(__FILE__, __LINE__); \
  }

#endif /*_DECAF_LANG_EXCEPTIONS_EXCEPTIONDEFINES_H_*/
