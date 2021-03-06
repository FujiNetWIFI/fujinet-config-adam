#ifdef BUILD_PC8801
/** 
 * Input routines
 */

#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "input.h"
#include "cursor.h"
#include "globals.h"
#include "bar.h"
#include "../set_wifi.h"
#include "../die.h"
#include "../hosts_and_devices.h"
#include "../select_file.h"
#include "../select_slot.h"

extern unsigned short entry_timer;
extern bool long_entry_displayed;
extern unsigned char copy_host_slot;
extern bool copy_mode;

/**
 * Get input from keyboard/joystick
 * @return keycode (or synthesized keycode if joystick)
 */
unsigned char input()
{
  return 0;
}

unsigned char input_ucase(void)
{
  unsigned char c = input();
  if ((c>='a') && (c<='z')) c&=~32;
  return c;
}

static void input_clear_bottom(void)
{
}

void input_line(unsigned char x, unsigned char y, unsigned char o, char *c, unsigned char len, bool password)
{
}

WSSubState input_set_wifi_select(void)
{
  unsigned char k=input();
  switch(k)
    {
    case 0x0D:
      set_wifi_set_ssid(bar_get());
      return WS_PASSWORD;
    case 0x84:
      return WS_CUSTOM;
    case 0x85:
      return WS_SCAN;
    case 0x86:
      state=HOSTS_AND_DEVICES;
      return WS_DONE;
    case 0xA0:
      bar_up();
      return WS_SELECT;
    case 0xA2:
      bar_down();
      return WS_SELECT;
    default:
      return WS_SELECT;
    }
}

void input_line_set_wifi_custom(char *c)
{
  input_line(0,19,0,c,32,false);
}

void input_line_set_wifi_password(char *c)
{
  input_line(0,19,0,c,64,true);
}

HDSubState input_hosts_and_devices_hosts(void)
{
  return 0;
}

HDSubState input_hosts_and_devices_devices(void)
{
  return 0;
}

void input_line_hosts_and_devices_host_slot(unsigned char i, unsigned char o, char *c)
{
  input_line(1,i+1,o,c,32,false);
}

void input_line_filter(char *c)
{
  input_line(0,19,0,c,32,false);
}

SFSubState input_select_file_choose(void)
{
  return SF_CHOOSE;
}

unsigned char input_select_file_new_type(void)
{
  return 0;
}

unsigned long input_select_file_new_size(unsigned char t)
{
  return 0;
}

unsigned long input_select_file_new_custom(void)
{
  return 0;
}

void input_select_file_new_name(char *c)
{
  input_line(0,19,0,c,255,false);
}

SSSubState input_select_slot_choose(void)
{
  return SS_CHOOSE;
}

DHSubState input_destination_host_slot_choose(void)
{
  return DH_CHOOSE;
}

SISubState input_show_info(void)
{
  return 0;
}

bool input_select_slot_build_eos_directory(void)
{
  return false;
}

void input_select_slot_build_eos_directory_label(char *c)
{
  input_line(0,19,0,c,12,false);
}

#endif /* BUILD_PC8801 */
