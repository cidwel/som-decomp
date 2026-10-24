; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E49
.include "src/rom/event_command_macros.inc"
event_4B0_command_1E49:
    event_wait 0
