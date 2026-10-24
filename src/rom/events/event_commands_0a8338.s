; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8338
.include "src/rom/event_command_macros.inc"
event_5F8_command_8338:
    event_wait 0
