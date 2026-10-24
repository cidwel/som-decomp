; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C0A
.include "src/rom/event_command_macros.inc"
event_1B9_command_6C0A:
    event_actor_walk 4, 0, 0
event_1B9_command_6C0D:
    event_wait 0
