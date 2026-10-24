; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $26D0
.include "src/rom/event_command_macros.inc"
event_4C8_command_26D0:
    event_wait 0
