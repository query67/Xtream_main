/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Tim Düsterhus <timwolla@php.net>                            |
   |          Go Kudo <zeriyoshi@php.net>                                 |
   +----------------------------------------------------------------------+
*/

#ifndef PHP_RANDOM_CSPRNG_H
#define PHP_RANDOM_CSPRNG_H

#include "php.h"

ZEND_ATTRIBUTE_NONNULL PHPAPI zend_result php_random_bytes(void *bytes, size_t size, bool should_throw);
ZEND_ATTRIBUTE_NONNULL PHPAPI zend_result php_random_bytes_ex(void *bytes, size_t size, char *errstr, size_t errstr_size);

ZEND_ATTRIBUTE_NONNULL PHPAPI zend_result php_random_int(zend_long min, zend_long max, zend_long *result, bool should_throw);

ZEND_ATTRIBUTE_NONNULL static inline zend_result php_random_bytes_throw(void *bytes, size_t size)
{
   return php_random_bytes(bytes, size, true);
}

ZEND_ATTRIBUTE_NONNULL static inline zend_result php_random_bytes_silent(void *bytes, size_t size)
{
   return php_random_bytes(bytes, size, false);
}

ZEND_ATTRIBUTE_NONNULL static inline zend_result php_random_int_throw(zend_long min, zend_long max, zend_long *result)
{
   return php_random_int(min, max, result, true);
}

ZEND_ATTRIBUTE_NONNULL static inline zend_result php_random_int_silent(zend_long min, zend_long max, zend_long *result)
{
   return php_random_int(min, max, result, false);
}

PHPAPI void php_random_csprng_shutdown(void);

#endif /* PHP_RANDOM_CSPRNG_H */
