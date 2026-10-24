; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2EEB
.include "src/rom/event_command_macros.inc"
event_10C_command_2EEB:
    event_actor_walk 5, 1, 0
