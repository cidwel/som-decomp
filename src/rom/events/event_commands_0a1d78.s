; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1D78
.include "src/rom/event_command_macros.inc"
event_4AC_command_1D78:
    event_wait 0
