; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $743E
.include "src/rom/event_command_macros.inc"
event_1CA_command_743E:
    event_actor_walk 5, 1, 0
