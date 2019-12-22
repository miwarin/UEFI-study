#ifndef _EFI_H_
#define _EFI_H_

struct  EFI_INPUT_KEY
{
  unsigned short ScanCode;
  unsigned short UnicodeChar;
};

struct EFI_GUID {
  unsigned int Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned char Data4[8];
};

struct  EFI_SYSTEM_TABLE
{
  char __buf1[44];
  struct  EFI_SIMPLE_TEXT_INPUT_PROTOCOL
  {
    unsigned long long _buf;
    unsigned long long (*ReadKeyStroke)
    (
      struct  EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This,
      struct EFI_INPUT_KEY* Key
    );
    void* WaitForKey;
  }* ConIn;

  unsigned long long __buf2;
  
  struct  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
  {
    unsigned long long _buf;
    unsigned long long (*OutputString)
    (
      struct  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
      unsigned short* String
    );
    unsigned long long _buf2[4];
    unsigned long long (*ClearScreen)
    (
      struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This
    );
  }* ConOut;

  unsigned long long __buf3[3];
  struct EFI_BOOT_SERVICES
  {
    char _buf1[24];
    unsigned long long _buf2[2];
    unsigned long long _buf3[5];
    unsigned long long _buf4[2];
    unsigned long long (*WaitForEvent)
    (
      unsigned long long NumberOfEvents,
      void** Event,
      unsigned long long* Index
    );
    unsigned long long _buf4_2[3];
    unsigned long long _buf5[9];
    unsigned long long _buf6[5];
    unsigned long long _buf7[2];

    unsigned long long (*SetWatchdogTimer)
    (
      unsigned long long Timeout,
      unsigned long long WatchdogCode,
      unsigned long long DataSize,
      unsigned short* WatchdogData
    );

    unsigned long long _buf8[2];
    unsigned long long _buf9[3];
    unsigned long long _buf10[2];
    unsigned long long (*LocateProtocol)(
      struct EFI_GUID* Protocol,
      void* Registration,
      void** Interface
    );
    unsigned long long _buf10_2[2];

    unsigned long long _buf11;
    unsigned long long _buf12[3];
  }* BootServices;
};

struct EFI_GRAPHICS_OUTPUT_BLT_PIXEL
{
  unsigned char Blue;
  unsigned char Green;
  unsigned char Red;
  unsigned char Reserved;
};

struct EFI_GRAPHICS_OUTPUT_PROTOCOL
{
  unsigned long long _buf[3];
  struct EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
  {
    unsigned int MaxMode;
    unsigned int Mode;
    struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
    {
      unsigned int Version;
      unsigned int HorizontalResolution;
      unsigned int VerticalResolution;
      enum EFI_GRAPHICS_PIXEL_FORMAT
      {
        PixelRedGreenBlueReserved8BitPerColor,
        PixelBlueGreenRedReserved8BitPerColor,
        PixelBitMask,
        PixelBitOnly,
        PixelFormatMax
      } PixelFormat;
    }* Info;
    unsigned long long SizeOfInfo;
    unsigned long long FrameBufferBase;
  }* Mode;
};

struct EFI_SIMPLE_POINTER_STATE
{
  int RelativeMovementX;
  int RelativeMovementY;
  int RelativeMovementZ;
  unsigned char LeftButton;
  unsigned char RightButton;
};

struct EFI_SIMPLE_POINTER_PROTOCOL
{
  unsigned long long (*Reset)
  (
    struct EFI_SIMPLE_POINTER_PROTOCOL* This,
    unsigned char ExtendedVerification
  );
  unsigned long long (*GetState)
  (
    struct EFI_SIMPLE_POINTER_PROTOCOL* This,
    struct EFI_SIMPLE_POINTER_STATE* State
  );
  void* WaitForInput;
};

extern struct  EFI_SYSTEM_TABLE* ST;
extern struct EFI_GRAPHICS_OUTPUT_PROTOCOL* GOP;
extern struct EFI_SIMPLE_POINTER_PROTOCOL* SPP;
void efi_init(struct EFI_SYSTEM_TABLE* SystemTable);

#endif
