; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2681
.include "src/rom/event_command_macros.inc"
event_4C8_command_2681:
    event_wait 0
