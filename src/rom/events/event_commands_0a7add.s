; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7ADD
.include "src/rom/event_command_macros.inc"
event_5F8_command_7ADD:
    event_wait 48
