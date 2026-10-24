; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E025
.include "src/rom/event_command_macros.inc"
event_39F_command_E025:
    event_wait 0
