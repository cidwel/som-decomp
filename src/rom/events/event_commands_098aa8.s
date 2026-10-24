; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8AA8
.include "src/rom/event_command_macros.inc"
event_1F6_command_8AA8:
    event_actor_walk 2, 0, 8
event_1F6_command_8AAB:
    event_actor_walk 3, 1, 0
event_1F6_command_8AAE:
    event_wait_idle 
