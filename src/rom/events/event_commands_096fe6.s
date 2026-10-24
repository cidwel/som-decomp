; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6FE6
.include "src/rom/event_command_macros.inc"
event_1C1_command_6FE6:
    event_wait 0
