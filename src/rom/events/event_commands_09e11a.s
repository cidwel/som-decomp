; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E11A
.include "src/rom/event_command_macros.inc"
event_3A7_command_E11A:
    event_wait 0
