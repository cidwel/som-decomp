; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B355
.include "src/rom/event_command_macros.inc"
event_29C_command_B355:
    event_decrement_flag 1
event_29C_command_B357:
    event_screen_word 6, 65535
event_29C_command_B35B:
    event_wait 16
event_29C_command_B35D:
    event_change_map 427
event_29C_command_B35F:
    event_increment_flag 40
event_29C_command_B361:
    event_jump 669
event_29C_command_B363:
    event_end 
event_29D_command_B364:
    event_call 1998
event_29D_command_B366:
    event_end 
event_29E_command_B367:
    event_freeze 
event_29E_command_B368:
    event_screen 8
