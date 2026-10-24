; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DDEF
.include "src/rom/event_command_macros.inc"
event_397_command_DDEF:
    event_call 1825
