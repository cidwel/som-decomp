; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $29E5
.include "src/rom/event_command_macros.inc"
event_106_command_29E5:
    event_actor_walk 5, 1, 0
