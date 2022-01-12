/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __DSKQUOTA_H
#define __DSKQUOTA_H

#include <windows.h>
#include <ole2.h>
#include <olectl.h>

#ifdef INITGUIDS
#include <initguid.h>
#endif

DEFINE_GUID(CLSID_DiskQuotaControl,0x7988b571,0xec89,0x11cf,0x9c,0x0,0x0,0xaa,0x0,0xa1,0x4f,0x56);
DEFINE_GUID(IID_IDiskQuotaControl,0x7988b572,0xec89,0x11cf,0x9c,0x0,0x0,0xaa,0x0,0xa1,0x4f,0x56);
DEFINE_GUID(IID_IDiskQuotaUser,0x7988b574,0xec89,0x11cf,0x9c,0x0,0x0,0xaa,0x0,0xa1,0x4f,0x56);
DEFINE_GUID(IID_IDiskQuotaUserBatch,0x7988b576,0xec89,0x11cf,0x9c,0x0,0x0,0xaa,0x0,0xa1,0x4f,0x56);
DEFINE_GUID(IID_IEnumDiskQuotaUsers,0x7988b577,0xec89,0x11cf,0x9c,0x0,0x0,0xaa,0x0,0xa1,0x4f,0x56);
DEFINE_GUID(IID_IDiskQuotaEvents,0x7988b579,0xec89,0x11cf,0x9c,0x0,0x0,0xaa,0x0,0xa1,0x4f,0x56);

#define DISKQUOTA_STATE_DISABLED 0x00000000
#define DISKQUOTA_STATE_TRACK 0x00000001
#define DISKQUOTA_STATE_ENFORCE 0x00000002
#define DISKQUOTA_STATE_MASK 0x00000003
#define DISKQUOTA_FILESTATE_INCOMPLETE 0x00000100
#define DISKQUOTA_FILESTATE_REBUILDING 0x00000200
#define DISKQUOTA_FILESTATE_MASK 0x00000300

#define DISKQUOTA_SET_DISABLED(s) ((s) &= ~DISKQUOTA_STATE_MASK)
#define DISKQUOTA_SET_TRACKED(s) ((s) |= (DISKQUOTA_STATE_MASK & DISKQUOTA_STATE_TRACK))
#define DISKQUOTA_SET_ENFORCED(s) ((s) |= (DISKQUOTA_STATE_ENFORCE & DISKQUOTA_STATE_ENFORCE))
#define DISKQUOTA_IS_DISABLED(s) (DISKQUOTA_STATE_DISABLED==((s) & DISKQUOTA_STATE_MASK))
#define DISKQUOTA_IS_TRACKED(s) (DISKQUOTA_STATE_TRACK==((s) & DISKQUOTA_STATE_MASK))
#define DISKQUOTA_IS_ENFORCED(s) (DISKQUOTA_STATE_ENFORCE==((s) & DISKQUOTA_STATE_MASK))
#define DISKQUOTA_FILE_INCOMPLETE(s) (0!=((s) & DISKQUOTA_FILESTATE_INCOMPLETE))
#define DISKQUOTA_FILE_REBUILDING(s) (0!=((s) & DISKQUOTA_FILESTATE_REBUILDING))

#define DISKQUOTA_LOGFLAG_USER_THRESHOLD 0x00000001
#define DISKQUOTA_LOGFLAG_USER_LIMIT 0x00000002

#define DISKQUOTA_IS_LOGGED_USER_THRESHOLD(f) (0!=((f) & DISKQUOTA_LOGFLAG_USER_THRESHOLD))
#define DISKQUOTA_IS_LOGGED_USER_LIMIT(f) (0!=((f) & DISKQUOTA_LOGFLAG_USER_LIMIT))
#define DISKQUOTA_SET_LOG_USER_THRESHOLD(f,yn) ((f &= ~DISKQUOTA_LOGFLAG_USER_THRESHOLD) |= ((yn) ? DISKQUOTA_LOGFLAG_USER_THRESHOLD : 0))
#define DISKQUOTA_SET_LOG_USER_LIMIT(f,yn) ((f &= ~DISKQUOTA_LOGFLAG_USER_LIMIT) |= ((yn) ? DISKQUOTA_LOGFLAG_USER_LIMIT : 0))

typedef struct DiskQuotaUserInformation {
  LONGLONG QuotaUsed;
  LONGLONG QuotaThreshold;
  LONGLONG QuotaLimit;
} DISKQUOTA_USER_INFORMATION,*PDISKQUOTA_USER_INFORMATION;

#define DISKQUOTA_USERNAME_RESOLVE_NONE 0
#define DISKQUOTA_USERNAME_RESOLVE_SYNC 1
#define DISKQUOTA_USERNAME_RESOLVE_ASYNC 2

#define DISKQUOTA_USER_ACCOUNT_RESOLVED 0
#define DISKQUOTA_USER_ACCOUNT_UNAVAILABLE 1
#define DISKQUOTA_USER_ACCOUNT_DELETED 2
#define DISKQUOTA_USER_ACCOUNT_INVALID 3
#define DISKQUOTA_USER_ACCOUNT_UNKNOWN 4
#define DISKQUOTA_USER_ACCOUNT_UNRESOLVED 5

#undef INTERFACE
#define INTERFACE IDiskQuotaUser
DECLARE_INTERFACE_(IDiskQuotaUser,IUnknown) {
  STDMETHOD(GetID)(THIS_ ULONG *pulID) PURE;
  STDMETHOD(GetName)(THIS_ LPWSTR pszAccountContainer,DWORD cchAccountContainer,LPWSTR pszLogonName,DWORD cchLogonName,LPWSTR pszDisplayName,DWORD cchDisplayName) PURE;
  STDMETHOD(GetSidLength)(THIS_ LPDWORD pdwLength) PURE;
  STDMETHOD(GetSid)(THIS_ LPBYTE pbSidBuffer,DWORD cbSidBuffer) PURE;
  STDMETHOD(GetQuotaThreshold)(THIS_ PLONGLONG pllThreshold) PURE;
  STDMETHOD(GetQuotaThresholdText)(THIS_ LPWSTR pszText,DWORD cchText) PURE;
  STDMETHOD(GetQuotaLimit)(THIS_ PLONGLONG pllLimit) PURE;
  STDMETHOD(GetQuotaLimitText)(THIS_ LPWSTR pszText,DWORD cchText) PURE;
  STDMETHOD(GetQuotaUsed)(THIS_ PLONGLONG pllUsed) PURE;
  STDMETHOD(GetQuotaUsedText)(THIS_ LPWSTR pszText,DWORD cchText) PURE;
  STDMETHOD(GetQuotaInformation)(THIS_ LPVOID pbQuotaInfo,DWORD cbQuotaInfo) PURE;
  STDMETHOD(SetQuotaThreshold)(THIS_ LONGLONG llThreshold,WINBOOL fWriteThrough) PURE;
  STDMETHOD(SetQuotaLimit)(THIS_ LONGLONG llLimit,WINBOOL fWriteThrough) PURE;
  STDMETHOD(Invalidate)(THIS) PURE;
  STDMETHOD(GetAccountStatus)(THIS_ LPDWORD pdwStatus) PURE;
};
typedef IDiskQuotaUser DISKQUOTA_USER,*PDISKQUOTA_USER;

#undef INTERFACE
#define INTERFACE IEnumDiskQuotaUsers
DECLARE_INTERFACE_(IEnumDiskQuotaUsers,IUnknown) {
  STDMETHOD(Next)(THIS_ DWORD cUsers,PDISKQUOTA_USER *rgUsers,LPDWORD pcUsersFetched) PURE;
  STDMETHOD(Skip)(THIS_ DWORD cUsers) PURE;
  STDMETHOD(Reset)(THIS) PURE;
  STDMETHOD(Clone)(THIS_ IEnumDiskQuotaUsers **ppEnum) PURE;
};

typedef IEnumDiskQuotaUsers ENUM_DISKQUOTA_USERS,*PENUM_DISKQUOTA_USERS;

#undef INTERFACE
#define INTERFACE IDiskQuotaUserBatch
DECLARE_INTERFACE_(IDiskQuotaUserBatch,IUnknown) {
  STDMETHOD(Add)(THIS_ PDISKQUOTA_USER pUser) PURE;
  STDMETHOD(Remove)(THIS_ PDISKQUOTA_USER pUser) PURE;
  STDMETHOD(RemoveAll)(THIS) PURE;
  STDMETHOD(FlushToDisk)(THIS) PURE;
};

typedef IDiskQuotaUserBatch DISKQUOTA_USER_BATCH,*PDISKQUOTA_USER_BATCH;

#undef INTERFACE
#define INTERFACE IDiskQuotaControl
DECLARE_INTERFACE_(IDiskQuotaControl,IConnectionPointContainer) {
  STDMETHOD(Initialize)(THIS_ LPCWSTR pszPath,WINBOOL bReadWrite) PURE;
  STDMETHOD(SetQuotaState)(THIS_ DWORD dwState) PURE;
  STDMETHOD(GetQuotaState)(THIS_ LPDWORD pdwState) PURE;
  STDMETHOD(SetQuotaLogFlags)(THIS_ DWORD dwFlags) PURE;
  STDMETHOD(GetQuotaLogFlags)(THIS_ LPDWORD pdwFlags) PURE;
  STDMETHOD(SetDefaultQuotaThreshold)(THIS_ LONGLONG llThreshold) PURE;
  STDMETHOD(GetDefaultQuotaThreshold)(THIS_ PLONGLONG pllThreshold) PURE;
  STDMETHOD(GetDefaultQuotaThresholdText)(THIS_ LPWSTR pszText,DWORD cchText) PURE;
  STDMETHOD(SetDefaultQuotaLimit)(THIS_ LONGLONG llLimit) PURE;
  STDMETHOD(GetDefaultQuotaLimit)(THIS_ PLONGLONG pllLimit) PURE;
  STDMETHOD(GetDefaultQuotaLimitText)(THIS_ LPWSTR pszText,DWORD cchText) PURE;
  STDMETHOD(AddUserSid)(THIS_ PSID pUserSid,DWORD fNameResolution,PDISKQUOTA_USER *ppUser) PURE;
  STDMETHOD(AddUserName)(THIS_ LPCWSTR pszLogonName,DWORD fNameResolution,PDISKQUOTA_USER *ppUser) PURE;
  STDMETHOD(DeleteUser)(THIS_ PDISKQUOTA_USER pUser) PURE;
  STDMETHOD(FindUserSid)(THIS_ PSID pUserSid,DWORD fNameResolution,PDISKQUOTA_USER *ppUser) PURE;
  STDMETHOD(FindUserName)(THIS_ LPCWSTR pszLogonName,PDISKQUOTA_USER *ppUser) PURE;
  STDMETHOD(CreateEnumUsers)(THIS_ PSID *rgpUserSids,DWORD cpSids,DWORD fNameResolution,PENUM_DISKQUOTA_USERS *ppEnum) PURE;
  STDMETHOD(CreateUserBatch)(THIS_ PDISKQUOTA_USER_BATCH *ppBatch) PURE;
  STDMETHOD(InvalidateSidNameCache)(THIS) PURE;
  STDMETHOD(GiveUserNameResolutionPriority)(THIS_ PDISKQUOTA_USER pUser) PURE;
  STDMETHOD(ShutdownNameResolution)(THIS) PURE;
};

typedef IDiskQuotaControl DISKQUOTA_CONTROL,*PDISKQUOTA_CONTROL;

#undef INTERFACE
#define INTERFACE IDiskQuotaEvents
DECLARE_INTERFACE_(IDiskQuotaEvents,IUnknown) {
  STDMETHOD(OnUserNameChanged)(THIS_ PDISKQUOTA_USER pUser) PURE;
};

typedef IDiskQuotaEvents DISKQUOTA_EVENTS,*PDISKQUOTA_EVENTS;
#endif
