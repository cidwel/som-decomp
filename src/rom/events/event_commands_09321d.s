; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $321D
.include "src/rom/event_command_macros.inc"
event_10C_command_321D:
    event_wait 0
