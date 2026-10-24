; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6CD8
.include "src/rom/event_command_macros.inc"
event_1B9_command_6CD8:
    event_actor_walk 4, 1, 0
event_1B9_command_6CDB:
    event_wait 0
