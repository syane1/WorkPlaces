/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef H_CCHANNEL
#define H_CCHANNEL

#include <pchannel.h>

#define VCAPITYPE _stdcall
#define VCEXPORT

typedef VOID _stdcall CHANNEL_INIT_EVENT_FN(LPVOID pInitHandle,UINT event,LPVOID pData,UINT dataLength);
typedef CHANNEL_INIT_EVENT_FN *PCHANNEL_INIT_EVENT_FN;

#define CHANNEL_EVENT_INITIALIZED 0
#define CHANNEL_EVENT_CONNECTED 1
#define CHANNEL_EVENT_V1_CONNECTED 2
#define CHANNEL_EVENT_DISCONNECTED 3
#define CHANNEL_EVENT_TERMINATED 4

typedef VOID _stdcall CHANNEL_OPEN_EVENT_FN(DWORD openHandle,UINT event,LPVOID pData,UINT32 dataLength,UINT32 totalLength,UINT32 dataFlags);
typedef CHANNEL_OPEN_EVENT_FN *PCHANNEL_OPEN_EVENT_FN;

#define CHANNEL_EVENT_DATA_RECEIVED 10
#define CHANNEL_EVENT_WRITE_COMPLETE 11
#define CHANNEL_EVENT_WRITE_CANCELLED 12

#define CHANNEL_RC_OK 0
#define CHANNEL_RC_ALREADY_INITIALIZED 1
#define CHANNEL_RC_NOT_INITIALIZED 2
#define CHANNEL_RC_ALREADY_CONNECTED 3
#define CHANNEL_RC_NOT_CONNECTED 4
#define CHANNEL_RC_TOO_MANY_CHANNELS 5
#define CHANNEL_RC_BAD_CHANNEL 6
#define CHANNEL_RC_BAD_CHANNEL_HANDLE 7
#define CHANNEL_RC_NO_BUFFER 8
#define CHANNEL_RC_BAD_INIT_HANDLE 9
#define CHANNEL_RC_NOT_OPEN 10
#define CHANNEL_RC_BAD_PROC 11
#define CHANNEL_RC_NO_MEMORY 12
#define CHANNEL_RC_UNKNOWN_CHANNEL_NAME 13
#define CHANNEL_RC_ALREADY_OPEN 14
#define CHANNEL_RC_NOT_IN_VIRTUALCHANNELENTRY 15
#define CHANNEL_RC_NULL_DATA 16
#define CHANNEL_RC_ZERO_LENGTH 17

#define VIRTUAL_CHANNEL_VERSION_WIN2000 1

#ifdef __cplusplus
extern "C" {
#endif

  typedef UINT _stdcall VIRTUALCHANNELINIT(LPVOID *ppInitHandle,PCHANNEL_DEF pChannel,INT channelCount,ULONG versionRequested,PCHANNEL_INIT_EVENT_FN pChannelInitEventProc);
  typedef VIRTUALCHANNELINIT *PVIRTUALCHANNELINIT;
  typedef UINT _stdcall VIRTUALCHANNELOPEN(LPVOID pInitHandle,LPDWORD pOpenHandle,PCHAR pChannelName,PCHANNEL_OPEN_EVENT_FN pChannelOpenEventProc);
  typedef VIRTUALCHANNELOPEN *PVIRTUALCHANNELOPEN;
  typedef UINT _stdcall VIRTUALCHANNELCLOSE(DWORD openHandle);
  typedef VIRTUALCHANNELCLOSE *PVIRTUALCHANNELCLOSE;
  typedef UINT _stdcall VIRTUALCHANNELWRITE(DWORD openHandle,LPVOID pData,ULONG dataLength,LPVOID pUserData);
  typedef VIRTUALCHANNELWRITE *PVIRTUALCHANNELWRITE;

  typedef struct tagCHANNEL_ENTRY_POINTS {
    DWORD cbSize;
    DWORD protocolVersion;
    PVIRTUALCHANNELINIT pVirtualChannelInit;
    PVIRTUALCHANNELOPEN pVirtualChannelOpen;
    PVIRTUALCHANNELCLOSE pVirtualChannelClose;
    PVIRTUALCHANNELWRITE pVirtualChannelWrite;
  } CHANNEL_ENTRY_POINTS,*PCHANNEL_ENTRY_POINTS;

  typedef WINBOOL _stdcall VIRTUALCHANNELENTRY(PCHANNEL_ENTRY_POINTS pEntryPoints);
  typedef VIRTUALCHANNELENTRY *PVIRTUALCHANNELENTRY;

#ifdef __cplusplus
}
#endif
#endif
