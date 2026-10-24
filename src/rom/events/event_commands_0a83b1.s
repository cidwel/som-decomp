; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $83B1
.include "src/rom/event_command_macros.inc"
event_5F8_command_83B1:
    event_wait 0
