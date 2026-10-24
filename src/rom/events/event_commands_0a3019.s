; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3019
.include "src/rom/event_command_macros.inc"
event_4E1_command_3019:
    event_wait 0
