; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F42
.include "src/rom/event_command_macros.inc"
event_1BD_command_6F42:
    event_end 
event_1BD_command_6F43:
    event_end 
event_1BD_command_6F44:
    event_jump 453
event_1BD_command_6F46:
    event_change_map 55
event_1BD_command_6F48:
    event_jump 1797
event_1BD_command_6F4A:
    event_unfreeze 
event_1BD_command_6F4B:
    event_end 
event_1BE_command_6F4C:
    event_test_flag_range 20, 0, 1
event_1BE_command_6F4F:
    event_jump 0
event_1BE_command_6F51:
    event_freeze 
event_1BE_command_6F52:
    event_call 1925
event_1BE_command_6F54:
    event_screen 2
event_1BE_command_6F56:
    event_wait 16
