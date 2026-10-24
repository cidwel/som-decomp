; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6451
.include "src/rom/event_command_macros.inc"
event_1A5_command_6451:
    event_wait 0
