/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#ifndef incl_HPHP_JIT_BACK_END_X64_H
#define incl_HPHP_JIT_BACK_END_X64_H

#include "hphp/runtime/vm/jit/back-end.h"

namespace HPHP { namespace jit { namespace x64 {

//////////////////////////////////////////////////////////////////////

std::unique_ptr<BackEnd> newBackEnd();

//////////////////////////////////////////////////////////////////////

constexpr int kCallLen = 5;
constexpr int kJmpLen = 5;
constexpr int kJccLen = 6;
constexpr int kJmpImmBytes = 4;
constexpr int kRipLeaLen = 7;

constexpr int kMovLen = 10;
constexpr int kMovImmOff = 2;

/*
 * Cache alignment is required for mutable instructions on x64 to make sure
 * mutations don't "tear" on remote CPUs.
 */
constexpr size_t kCacheLineSize = 64;
constexpr size_t kCacheLineMask = kCacheLineSize - 1;

//////////////////////////////////////////////////////////////////////

}}}

#endif
