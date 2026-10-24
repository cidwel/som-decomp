; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $36B1
.include "src/rom/event_command_macros.inc"
event_4E2_command_36B1:
    event_wait 0
