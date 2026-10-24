; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4069
.include "src/rom/event_command_macros.inc"
event_4E6_command_4069:
    event_actor_walk 7, 3, 0
event_4E6_command_406C:
    event_actor_animation 0, 140
event_4E6_command_406F:
    event_wait 0
