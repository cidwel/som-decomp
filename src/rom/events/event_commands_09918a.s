; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $918A
.include "src/rom/event_command_macros.inc"
event_207_command_918A:
    event_actor_walk 5, 1, 0
event_207_command_918D:
    event_wait 0
