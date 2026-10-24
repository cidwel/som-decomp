; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8130
.include "src/rom/event_command_macros.inc"
event_5F8_command_8130:
    event_wait 16
