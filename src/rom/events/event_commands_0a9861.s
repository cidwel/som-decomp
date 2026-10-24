; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9861
.include "src/rom/event_command_macros.inc"
event_7FE_command_9861:
    event_call 1864
event_7FE_command_9863:
    event_actor_walk 0, 1, 0
event_7FE_command_9866:
    event_call 1051
event_7FE_command_9868:
    event_wait 8
