; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8500
.include "src/rom/event_command_macros.inc"
event_1E7_command_8500:
    event_wait 0
