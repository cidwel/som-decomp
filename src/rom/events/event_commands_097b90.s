; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7B90
.include "src/rom/event_command_macros.inc"
event_1D4_command_7B90:
    event_wait 0
