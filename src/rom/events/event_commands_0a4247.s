; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4247
.include "src/rom/event_command_macros.inc"
event_4E7_command_4247:
    event_wait 8
