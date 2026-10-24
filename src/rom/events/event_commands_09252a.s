; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $252A
.include "src/rom/event_command_macros.inc"
event_0FD_command_252A:
    event_call 252
event_0FD_command_252C:
    event_world_transition 32
event_0FD_command_252E:
    event_call 247
event_0FD_command_2530:
    event_jump 1806
event_0FD_command_2532:
    event_end 
event_0FE_command_2533:
    event_object_command_37 50
