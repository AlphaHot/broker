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
 
#ifndef _DECAF_UTIL_RANDOM_H_
#define _DECAF_UTIL_RANDOM_H_

#include <decaf/lang/exceptions/IllegalArgumentException.h>
#include <decaf/util/Config.h>
#include <cmath>
#include <vector>

namespace decaf {
namespace util {

/**
 * Random Value Generator which is used to generate a stream of pseudorandom numbers.
 * <p>
 * The algorithms implemented by class Random use a protected utility method that
 * on each invocation can supply up to 32 pseudorandomly generated bits.
 *
 * @since 1.0
 */
class DECAF_API Random {
 private:
  static unsigned long long multiplier;

  /**
   * The boolean value indicating if the second Gaussian number is available.
   */
  bool haveNextNextGaussian;

  /**
   * It is associated with the internal state of this generator.
   */
  unsigned long long seed;

  /**
   * The second Gaussian generated number.
   */
  double nextNextGaussian;

 public:
  /**
   * Construct a random generator with the current time of day in
   * milliseconds as the initial state.
   *
   * @see #setSeed
   */
  Random();

  /**
   * Construct a random generator with the given <code>seed</code>
   * as the initial state.
   *
   * @param seed the seed that will determine the initial state of
   * this random number generator
   *
   * @see #setSeed
   */
  Random(unsigned long long seed);

  virtual ~Random();

 public:
  /**
   * Answers the next pseudo-random, uniformly distributed boolean
   * value generated by this generator.
   *
   * @return boolean a pseudo-random, uniformly distributed boolean
   * value
   */
  bool nextBoolean();

  /**
   * Generates a normally distributed random double number between
   * 0.0 inclusively and 1.0 exclusively.
   *
   * @return double
   *
   * @see #nextFloat
   */
  double nextDouble();

  /**
   * Generates a normally distributed random float number between
   * 0.0 inclusively and 1.0 exclusively.
   *
   * @return float a random float number between 0.0 and 1.0
   *
   * @see #nextDouble
   */
  float nextFloat();

  /**
   * Pseudo-randomly generates (approximately) a normally
   * distributed <code>double</code> value with mean 0.0 and a
   * standard deviation value of <code>1.0</code> using the <i>polar
   * method</i> of G. E. P. Box, M.  E. Muller, and G. Marsaglia, as
   * described by Donald E. Knuth in <i>The Art of Computer
   * Programming, Volume 2: Seminumerical Algorithms</i>, section
   * 3.4.1, subsection C, algorithm P
   *
   * @return double
   *
   * @see #nextDouble
   */
  double nextGaussian();

  /**
   * Generates a uniformly distributed 32-bit <code>int</code> value
   * from the this random number sequence.
   *
   * @return int uniformly distributed <code>int</code> value
   *
   * @see #next
   * @see #nextLong
   */
  int nextInt();

  /**
   * Returns to the caller a new pseudo-random integer value which
   * is uniformly distributed between 0 (inclusively) and the value
   * of <code>n</code> (exclusively).
   *
   * @param n
   *      The int value that defines the max value of the return.
   *
   * @return the next pseudo random int value.
   *
   * @throws IllegalArgumentException if n is less than or equal to zero.
   */
  int nextInt(int n);

  /**
   * Generates a uniformly distributed 64-bit <code>int</code> value
   * from the this random number sequence.
   *
   * @return 64-bit <code>int</code> random number
   *
   * @see #next
   * @see #nextInt()
   * @see #nextInt(int)
   */
  long long nextLong();

 public:  // Virtual Methods
  /**
   * Modifies the byte array by a random sequence of bytes generated
   * by this random number generator.
   *
   * @param buf non-null array to contain the new random bytes
   *
   * @see #next
   */
  virtual void nextBytes(std::vector<unsigned char> &buf);

  /**
   * Modifies the byte array by a random sequence of bytes generated
   * by this random number generator.
   *
   * @param buf non-null array to contain the new random bytes
   *
   * @see #next
   *
   * @throw NullPointerException if buff is NULL
   * @throw IllegalArgumentException if size is negative
   */
  virtual void nextBytes(unsigned char *buf, int size);

  /**
   * Modifies the seed using linear congruential formula presented
   * in <i>The Art of Computer Programming, Volume 2</i>, Section
   * 3.2.1.
   *
   * @param newSeed the seed that alters the state of the random number
   * generator
   *
   * @see #next
   * @see #Random()
   * @see #Random(long)
   */
  virtual void setSeed(unsigned long long newSeed);

 protected:  // Virtual method used by all non-virtual methods in Random.
  /**
   * Answers a pseudo-random uniformly distributed <code>int</code>
   * value of the number of bits specified by the argument
   * <code>bits</code> as described by Donald E. Knuth in <i>The Art
   * of Computer Programming, Volume 2: Seminumerical
   * Algorithms</i>, section 3.2.1.
   *
   * @return int a pseudo-random generated int number
   * @param bits number of bits of the returned value
   *
   * @see #nextBytes
   * @see #nextDouble
   * @see #nextFloat
   * @see #nextInt()
   * @see #nextInt(int)
   * @see #nextGaussian
   * @see #nextLong
   */
  virtual int next(int bits);
};
}  // namespace util
}  // namespace decaf

#endif /*_DECAF_UTIL_RANDOM_H_*/
