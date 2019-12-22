#include "efi.h"
#include "common.h"
#include "graphics.h"
#include "shell.h"
#include "gui.h"

#define MAX_COMMAND_LEN 100

void pstat(void)
{
  unsigned long long status;
  struct EFI_SIMPLE_POINTER_STATE s;
  unsigned long long waitidx;

  puts(L"1");
  SPP->Reset(SPP, FALSE);
  puts(L"2");

  while(1)
  {
    puts(L"3");
    ST->BootServices->WaitForEvent(1, &(SPP->WaitForInput),&waitidx);
    puts(L"4");
    status = SPP->GetState(SPP, &s);
    puts(L"5");
    if(!status)
    {
      puts(L"hoge");
      // puth(s.RelativeMovementX, 8);
      // puts(L" ");
      // puth(s.RelativeMovementY, 8);
      // puts(L" ");
      // puth(s.RelativeMovementZ, 8);
      // puts(L" ");
      // puth(s.LeftButton, 1);
      // puts(L" ");
      // puth(s.RightButton, 1);
      puts(L"\r\n");
    }
  }
}

void shell(void)
{
  unsigned short com[MAX_COMMAND_LEN];
  struct RECT r = {10, 10, 100, 200};

  while(TRUE)
  {
    puts(L"poiOS> ");
    if(gets(com, MAX_COMMAND_LEN) <= 0)
    {
      continue;
    }
    if(!strcmp(L"hello", com))
    {
      puts(L"Hello UEFI!\r\n");
    }
    else if(!strcmp(L"rect", com))
    {
      draw_rect(r, white);
    }
    else if(!strcmp(L"gui", com))
    {
      gui();
    }
    else if (!strcmp(L"pstat", com))
    {
      pstat();
    }
    else
    {
      puts(L"Command not found.\r\n");
    }
  }
}


