/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _PCIPROP_
#define _PCIPROP_

#include <winapifamily.h>
#include <devpropdef.h>

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#define DEFINE_PCI_ROOT_BUS_DEVPKEY(_DPKNAME, _PID) DEFINE_DEVPROPKEY ((_DPKNAME), 0xd817fc28, 0x793e, 0x4b9e, 0x99, 0x70, 0x46, 0x9d, 0x8b, 0xe6, 0x30, 0x73, (_PID))
#define DEFINE_PCI_DEVICE_DEVPKEY(_DPKNAME, _PID) DEFINE_DEVPROPKEY ((_DPKNAME), 0x3ab22e31, 0x8264, 0x4b4e, 0x9a, 0xf5, 0xa8, 0xd2, 0xd8, 0xe3, 0x3e, 0x62, (_PID))

DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_SecondaryInterface, 1);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_CurrentSpeedAndMode, 2);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_SupportedSpeedsAndModes, 3);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_DeviceIDMessagingCapable, 4);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_SecondaryBusWidth, 5);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_ExtendedConfigAvailable, 6);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_ExtendedPCIConfigOpRegionSupport, 7);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_ASPMSupport, 8);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_ClockPowerManagementSupport, 9);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_PCISegmentGroupsSupport, 10);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_MSISupport, 11);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_PCIExpressNativeHotPlugControl, 12);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_SHPCNativeHotPlugControl, 13);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_PCIExpressNativePMEControl, 14);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_PCIExpressAERControl, 15);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_PCIExpressCapabilityControl, 16);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_NativePciExpressControl, 17);
DEFINE_PCI_ROOT_BUS_DEVPKEY (DEVPKEY_PciRootBus_SystemMsiSupport, 18);

DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_DeviceType, 1);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_CurrentSpeedAndMode, 2);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_BaseClass, 3);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_SubClass, 4);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_ProgIf, 5);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_CurrentPayloadSize, 6);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_MaxPayloadSize, 7);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_MaxReadRequestSize, 8);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_CurrentLinkSpeed, 9);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_CurrentLinkWidth, 10);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_MaxLinkSpeed, 11);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_MaxLinkWidth, 12);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_ExpressSpecVersion, 13);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_InterruptSupport, 14);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_InterruptMessageMaximum, 15);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_BarTypes, 16);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_AERCapabilityPresent, 17);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_FirmwareErrorHandling, 18);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_Uncorrectable_Error_Mask, 19);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_Uncorrectable_Error_Severity, 20);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_Correctable_Error_Mask, 21);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_ECRC_Errors, 22);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_Error_Reporting, 23);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_RootError_Reporting, 24);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_S0WakeupSupported, 25);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_SriovSupport, 26);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_Label_Id, 27);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_Label_String, 28);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_AcsSupport, 29);
DEFINE_PCI_DEVICE_DEVPKEY (DEVPKEY_PciDevice_AriSupport, 30);

#define DevProp_PciRootBus_SecondaryInterface_PciConventional 0
#define DevProp_PciRootBus_SecondaryInterface_PciXMode1 1
#define DevProp_PciRootBus_SecondaryInterface_PciXMode2 2
#define DevProp_PciRootBus_SecondaryInterface_PciExpress 3

#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_33Mhz 0
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_66Mhz 1
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_66Mhz 2
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_100Mhz 3
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_133Mhz 4
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_66Mhz 5
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_100Mhz 6
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_133Mhz 7
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_66Mhz 8
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_100Mhz 9
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_133Mhz 10
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_66Mhz 11
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_100Mhz 12
#define DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_133Mhz 13

#define DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_33Mhz 1
#define DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_66Mhz 2
#define DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_66Mhz 4
#define DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_133Mhz 8
#define DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_266Mhz 16
#define DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_533Mhz 32

#define DevProp_PciRootBus_BusWidth_32Bits 0
#define DevProp_PciRootBus_BusWidth_64Bits 1

#define DevProp_PciDevice_DeviceType_PciConventional 0
#define DevProp_PciDevice_DeviceType_PciX 1
#define DevProp_PciDevice_DeviceType_PciExpressEndpoint 2
#define DevProp_PciDevice_DeviceType_PciExpressLegacyEndpoint 3
#define DevProp_PciDevice_DeviceType_PciExpressRootComplexIntegratedEndpoint 4
#define DevProp_PciDevice_DeviceType_PciExpressTreatedAsPci 5
#define DevProp_PciDevice_BridgeType_PciConventional 6
#define DevProp_PciDevice_BridgeType_PciX 7
#define DevProp_PciDevice_BridgeType_PciExpressRootPort 8
#define DevProp_PciDevice_BridgeType_PciExpressUpstreamSwitchPort 9
#define DevProp_PciDevice_BridgeType_PciExpressDownstreamSwitchPort 10
#define DevProp_PciDevice_BridgeType_PciExpressToPciXBridge 11
#define DevProp_PciDevice_BridgeType_PciXToExpressBridge 12
#define DevProp_PciDevice_BridgeType_PciExpressTreatedAsPci 13

#define DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_33MHz 0
#define DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_66MHz 1

#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode_Conventional_Pci 0x0
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_66Mhz 0x1
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_100Mhz 0x2
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_133MHZ 0x3
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_66Mhz 0x5
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_100Mhz 0x6
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_133Mhz 0x7
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_66MHz 0x9
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_100MHz 0xa
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_133MHz 0xb
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_66MHz 0xd
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_100MHz 0xe
#define DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_133MHz 0xf

#define DevProp_PciExpressDevice_PayloadOrRequestSize_128Bytes 0
#define DevProp_PciExpressDevice_PayloadOrRequestSize_256Bytes 1
#define DevProp_PciExpressDevice_PayloadOrRequestSize_512Bytes 2
#define DevProp_PciExpressDevice_PayloadOrRequestSize_1024Bytes 3
#define DevProp_PciExpressDevice_PayloadOrRequestSize_2048Bytes 4
#define DevProp_PciExpressDevice_PayloadOrRequestSize_4096Bytes 5

#define DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps 1
#define DevProp_PciExpressDevice_LinkSpeed_Five_Gbps 2

#define DevProp_PciExpressDevice_LinkWidth_By_1 1
#define DevProp_PciExpressDevice_LinkWidth_By_2 2
#define DevProp_PciExpressDevice_LinkWidth_By_4 4
#define DevProp_PciExpressDevice_LinkWidth_By_8 8
#define DevProp_PciExpressDevice_LinkWidth_By_12 12
#define DevProp_PciExpressDevice_LinkWidth_By_16 16
#define DevProp_PciExpressDevice_LinkWidth_By_32 32

#define DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps 1

#define DevProp_PciExpressDevice_Spec_Version_10 1
#define DevProp_PciExpressDevice_Spec_Version_11 2

#define DevProp_PciDevice_InterruptType_LineBased 1
#define DevProp_PciDevice_InterruptType_Msi 2
#define DevProp_PciDevice_InterruptType_MsiX 4

#define DevProp_PciDevice_IoBarCount(_PD) ((_PD) & 0xff)
#define DevProp_PciDevice_NonPrefetchable_MemoryBarCount(_PD) (((_PD) >> 8) & 0xff)
#define DevProp_PciDevice_32BitPrefetchable_MemoryBarCount(_PD) (((_PD) >> 16) & 0xff)
#define DevProp_PciDevice_64BitPrefetchable_MemoryBarCount(_PD) (((_PD) >> 24) & 0xff)

#define DevProp_PciDevice_SriovSupport_Ok 0x0
#define DevProp_PciDevice_SriovSupport_MissingAcs 0x1
#define DevProp_PciDevice_SriovSupport_MissingPfDriver 0x2
#define DevProp_PciDevice_SriovSupport_NoBusResource 0x3
#define DevProp_PciDevice_SriovSupport_DidntGetVfBarSpace 0x4

#define DevProp_PciDevice_AcsSupport_Present 0x0
#define DevProp_PciDevice_AcsSupport_NotNeeded 0x1
#define DevProp_PciDevice_AcsSupport_Missing 0x2

#endif
#endif
