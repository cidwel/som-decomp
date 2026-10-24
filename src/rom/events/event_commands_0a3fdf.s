; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3FDF
.include "src/rom/event_command_macros.inc"
event_4E6_command_3FDF:
    event_actor_walk 6, 1, 0
event_4E6_command_3FE2:
    event_wait 0
