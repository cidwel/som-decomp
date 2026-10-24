; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $913E
.include "src/rom/event_command_macros.inc"
event_205_command_913E:
    event_actor_walk 5, 1, 0
event_205_command_9141:
    event_wait 0
