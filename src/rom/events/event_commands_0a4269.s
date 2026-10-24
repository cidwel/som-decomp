; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4269
.include "src/rom/event_command_macros.inc"
event_4E8_command_4269:
    event_wait 8
