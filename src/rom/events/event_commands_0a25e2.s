; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $25E2
.include "src/rom/event_command_macros.inc"
event_4C8_command_25E2:
    event_wait 0
