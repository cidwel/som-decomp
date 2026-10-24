; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3EA5
.include "src/rom/event_command_macros.inc"
event_4E6_command_3EA5:
    event_wait 0
