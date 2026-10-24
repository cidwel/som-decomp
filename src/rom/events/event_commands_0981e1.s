; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $81E1
.include "src/rom/event_command_macros.inc"
event_1E1_command_81E1:
    event_wait 0
