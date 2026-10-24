; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B4B
.include "src/rom/event_command_macros.inc"
event_66D_command_8B4B:
    event_call 83
event_66D_command_8B4D:
    event_actor_walk 5, 0, 63
event_66D_command_8B50:
    event_actor_walk 6, 0, 63
