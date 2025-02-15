/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d376e984db0db6ccd9356f632f9d7e1382b2afb7 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Generator_rewind, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Generator_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Generator_current, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Generator_key arginfo_class_Generator_current

#define arginfo_class_Generator_next arginfo_class_Generator_rewind

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Generator_send, 0, 1, IS_MIXED, 0)
ZEND_ARG_TYPE_INFO(0, value, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Generator_throw, 0, 1, IS_MIXED, 0)
ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Generator_getReturn arginfo_class_Generator_current

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Generator___debugInfo, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Generator, rewind);
ZEND_METHOD(Generator, valid);
ZEND_METHOD(Generator, current);
ZEND_METHOD(Generator, key);
ZEND_METHOD(Generator, next);
ZEND_METHOD(Generator, send);
ZEND_METHOD(Generator, throw);
ZEND_METHOD(Generator, getReturn);
ZEND_METHOD(Generator, __debugInfo);

static const zend_function_entry class_Generator_methods[] = {
	ZEND_ME(Generator, rewind, arginfo_class_Generator_rewind, ZEND_ACC_PUBLIC)
		ZEND_ME(Generator, valid, arginfo_class_Generator_valid, ZEND_ACC_PUBLIC)
			ZEND_ME(Generator, current, arginfo_class_Generator_current, ZEND_ACC_PUBLIC)
				ZEND_ME(Generator, key, arginfo_class_Generator_key, ZEND_ACC_PUBLIC)
					ZEND_ME(Generator, next, arginfo_class_Generator_next, ZEND_ACC_PUBLIC)
						ZEND_ME(Generator, send, arginfo_class_Generator_send, ZEND_ACC_PUBLIC)
							ZEND_ME(Generator, throw, arginfo_class_Generator_throw, ZEND_ACC_PUBLIC)
								ZEND_ME(Generator, getReturn, arginfo_class_Generator_getReturn, ZEND_ACC_PUBLIC)
									ZEND_ME(Generator, __debugInfo, arginfo_class_Generator___debugInfo, ZEND_ACC_PUBLIC)
										ZEND_FE_END};

static zend_class_entry *register_class_Generator(zend_class_entry *class_entry_Iterator)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "Generator", class_Generator_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL | ZEND_ACC_NO_DYNAMIC_PROPERTIES | ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_Iterator);

	return class_entry;
}

static zend_class_entry *register_class_ClosedGeneratorException(zend_class_entry *class_entry_Exception)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ClosedGeneratorException", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Exception, 0);

	return class_entry;
}
