; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5C29
.include "src/rom/event_command_macros.inc"
event_51D_command_5C29:
    event_actor_walk 4, 1, 63
event_51D_command_5C2C:
    event_actor_walk 5, 1, 63
