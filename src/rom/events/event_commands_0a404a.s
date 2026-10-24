; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $404A
.include "src/rom/event_command_macros.inc"
event_4E6_command_404A:
    event_actor_walk 4, 3, 0
event_4E6_command_404D:
    event_actor_animation 0, 140
event_4E6_command_4050:
    event_wait 16
