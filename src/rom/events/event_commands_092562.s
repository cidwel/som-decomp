; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2562
.include "src/rom/event_command_macros.inc"
event_0FE_command_2562:
    event_call 252
event_0FE_command_2564:
    event_world_transition 33
event_0FE_command_2566:
    event_call 247
event_0FE_command_2568:
    event_jump 1797
event_0FE_command_256A:
    event_end 
