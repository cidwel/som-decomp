; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7E0B
.include "src/rom/event_command_macros.inc"
event_5F8_command_7E0B:
    event_wait 0
