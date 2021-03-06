/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _API_SET_H_
#define _API_SET_H_

#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

#define API_SET_PREFIX_NAME_A "API-"
#define API_SET_PREFIX_NAME_U L"API-"

#define API_SET_EXTENSION_NAME_A "EXT-"
#define API_SET_EXTENSION_NAME_U L"EXT-"

#define API_SET_SCHEMA_NAME ApiSetSchema
#define API_SET_SECTION_NAME  ".apiset"
#define API_SET_SCHEMA_SUFFIX L".sys"

#define API_SET_SCHEMA_VERSION __MSABI_LONG(2U)

#define API_SET_HELPER_NAME ApiSetHelp

#define API_SET_LOAD_SCHEMA_ORDINAL 1
#define API_SET_LOOKUP_ORDINAL 2
#define API_SET_RELEASE_SCHEMA_ORDINAL 3

#define API_SET_STRING_X(s) #s
#define API_SET_STRING(s) API_SET_STRING_X(s)
#define API_SET_STRING_U_Y(s) L ## s
#define API_SET_STRING_U_X(s) API_SET_STRING_U_Y(s)
#define API_SET_STRING_U(s) API_SET_STRING_U_X(API_SET_STRING(s))

#define API_SET_OVERRIDE(X) X##Implementation
#define API_SET_LEGACY_OVERRIDE_DEF(X) X = API_SET_OVERRIDE(X)
#define API_SET_OVERRIDE_DEF(X) API_SET_LEGACY_OVERRIDE_DEF(X) PRIVATE

#define API_SET_PRIVATE(X) X PRIVATE

#undef API_SET
#undef API_SET_LIBRARY

#ifdef _API_SET_HOST
#define API_SET(X) X PRIVATE
#define API_SET_LIBRARY(X)
#else
#define API_SET_LIBRARY(X) LIBRARY X
#ifndef _API_SET_LEGACY_TARGET
#define API_SET(X) X
#else
#define API_SET(X) X = _API_SET_LEGACY_TARGET##.##X
#undef API_SET_PRIVATE
#define API_SET_PRIVATE(X) X = _API_SET_LEGACY_TARGET##.##X PRIVATE
#endif

#endif

#ifdef _NTDEF_
  typedef struct _API_SET_VALUE_ENTRY {
    ULONG NameOffset;
    ULONG NameLength;
    ULONG ValueOffset;
    ULONG ValueLength;
  } API_SET_VALUE_ENTRY, *PAPI_SET_VALUE_ENTRY;

  typedef const API_SET_VALUE_ENTRY *PCAPI_SET_VALUE_ENTRY;

  typedef struct _API_SET_VALUE_ARRAY {
    ULONG Count;
    API_SET_VALUE_ENTRY Array[1];
  } API_SET_VALUE_ARRAY,*PAPI_SET_VALUE_ARRAY;

  typedef const API_SET_VALUE_ARRAY *PCAPI_SET_VALUE_ARRAY;

  typedef struct _API_SET_NAMESPACE_ENTRY {
    ULONG NameOffset;
    ULONG NameLength;
    ULONG DataOffset;
  } API_SET_NAMESPACE_ENTRY, *PAPI_SET_NAMESPACE_ENTRY;

  typedef const API_SET_NAMESPACE_ENTRY *PCAPI_SET_NAMESPACE_ENTRY;

  typedef struct _API_SET_NAMESPACE_ARRAY {
    ULONG Version;
    ULONG Count;
    API_SET_NAMESPACE_ENTRY Array[1];
  } API_SET_NAMESPACE_ARRAY, *PAPI_SET_NAMESPACE_ARRAY;

  typedef const API_SET_NAMESPACE_ARRAY *PCAPI_SET_NAMESPACE_ARRAY;

  typedef NTSTATUS (NTAPI *PAPI_SET_LOAD_SCHEMA_RTN)(PCSTR, PCAPI_SET_NAMESPACE_ARRAY *, PVOID *);
  typedef NTSTATUS (NTAPI *PAPI_SET_LOOKUP_HELPER_RTN)(PCAPI_SET_NAMESPACE_ARRAY, PCSTR, PCSTR, PBOOLEAN, PSTR, ULONG);
  typedef NTSTATUS (NTAPI *PAPI_SET_RELEASE_SCHEMA_RTN)(PVOID);

  NTSTATUS NTAPI ApiSetResolveToHost(PCAPI_SET_NAMESPACE_ARRAY ApiSetSchema, PCUNICODE_STRING FileNameIn, PCUNICODE_STRING ParentName, PBOOLEAN Resolved, PUNICODE_STRING HostBinary);

#endif

#ifdef __cplusplus
}
#endif

#endif /* _API_SET_H_ */
