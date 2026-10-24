; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5F65
.include "src/rom/event_command_macros.inc"
event_52E_command_5F65:
    event_change_map 861
event_52E_command_5F67:
    event_jump 1796
event_52E_command_5F69:
    event_end 
event_52F_command_5F6A:
    event_freeze 
event_52F_command_5F6B:
    event_call 1287
event_52F_command_5F6D:
    event_increment_flag 53
event_52F_command_5F6F:
    event_change_map 861
event_52F_command_5F71:
    event_screen_word 6, 15
event_52F_command_5F75:
    event_call 1925
event_52F_command_5F77:
    event_screen 2
event_52F_command_5F79:
    event_wait 8
event_52F_command_5F7B:
    event_screen 8
event_52F_command_5F7D:
    event_call 1151
event_52F_command_5F7F:
    event_increment_flag 248
