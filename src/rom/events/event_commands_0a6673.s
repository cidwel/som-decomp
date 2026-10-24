; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6673
.include "src/rom/event_command_macros.inc"
event_558_command_6673:
    event_wait 0
