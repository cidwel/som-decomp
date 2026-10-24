; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1CE4
.include "src/rom/event_command_macros.inc"
event_0D5_command_1CE4:
    event_wait 0
