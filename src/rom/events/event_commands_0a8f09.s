; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8F09
.include "src/rom/event_command_macros.inc"
event_687_command_8F09:
    event_hero_command 70
event_687_command_8F0B:
    event_set_flag 215, 1
event_687_command_8F0E:
    event_refresh_objects 
event_687_command_8F0F:
    event_jump 1806
event_687_command_8F11:
    event_end 
event_688_command_8F12:
    event_call 2
event_688_command_8F14:
    event_call 1663
event_688_command_8F16:
    event_set_flag 216, 2
event_688_command_8F19:
    event_refresh_objects 
event_688_command_8F1A:
    event_end 
event_689_command_8F1B:
    event_call 2
