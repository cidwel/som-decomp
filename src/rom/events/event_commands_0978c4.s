; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $78C4
.include "src/rom/event_command_macros.inc"
event_1CF_command_78C4:
    event_increment_flag 21
event_1CF_command_78C6:
    event_freeze 
event_1CF_command_78C7:
    event_gather 
event_1CF_command_78C8:
    event_change_map 86
event_1CF_command_78CA:
    event_jump 1823
event_1CF_command_78CC:
    event_end 
event_1D0_command_78CD:
    event_increment_flag 21
event_1D0_command_78CF:
    event_refresh_objects 
