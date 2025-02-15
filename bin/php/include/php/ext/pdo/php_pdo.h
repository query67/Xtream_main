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
  | Author: Wez Furlong <wez@php.net>                                    |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_PDO_H
#define PHP_PDO_H

#include "zend.h"

PHPAPI extern zend_module_entry pdo_module_entry;
#define phpext_pdo_ptr &pdo_module_entry

PHPAPI extern zend_class_entry *pdo_dbh_ce;
PHPAPI extern zend_object *pdo_dbh_new(zend_class_entry *ce);

#include "php_version.h"
#define PHP_PDO_VERSION PHP_VERSION

#ifdef PHP_WIN32
#if defined(PDO_EXPORTS) || (!defined(COMPILE_DL_PDO))
#define PDO_API __declspec(dllexport)
#elif defined(COMPILE_DL_PDO)
#define PDO_API __declspec(dllimport)
#else
#define PDO_API /* nothing special */
#endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#define PDO_API __attribute__((visibility("default")))
#else
#define PDO_API /* nothing special */
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(pdo);
PHP_MSHUTDOWN_FUNCTION(pdo);
PHP_MINFO_FUNCTION(pdo);

#define REGISTER_PDO_CLASS_CONST_LONG(const_name, value) \
  zend_declare_class_constant_long(php_pdo_get_dbh_ce(), const_name, sizeof(const_name) - 1, (zend_long)value);

#define LONG_CONST(c) (zend_long) c

#define PDO_CONSTRUCT_CHECK_COND dbh->driver
#define PDO_CONSTRUCT_CHECK_FAIL()                                                             \
  {                                                                                            \
    zend_throw_error(NULL, "%s object is uninitialized", ZSTR_VAL(Z_OBJ(EX(This))->ce->name)); \
  }

#define PDO_CONSTRUCT_CHECK        \
  if (!(PDO_CONSTRUCT_CHECK_COND)) \
  {                                \
    PDO_CONSTRUCT_CHECK_FAIL();    \
    RETURN_THROWS();               \
  }

#define PDO_CONSTRUCT_CHECK_WITH_CLEANUP(cleanup) \
  if (!(PDO_CONSTRUCT_CHECK_COND))                \
  {                                               \
    PDO_CONSTRUCT_CHECK_FAIL();                   \
    goto cleanup;                                 \
  }

#endif /* PHP_PDO_H */
