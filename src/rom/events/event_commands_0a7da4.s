; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7DA4
.include "src/rom/event_command_macros.inc"
event_5F8_command_7DA4:
    event_wait 0
