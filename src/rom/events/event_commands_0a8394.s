; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8394
.include "src/rom/event_command_macros.inc"
event_5F8_command_8394:
    event_wait 16
