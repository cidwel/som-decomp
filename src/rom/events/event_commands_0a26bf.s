; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $26BF
.include "src/rom/event_command_macros.inc"
event_4C8_command_26BF:
    event_wait 0
