; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $674A
.include "src/rom/event_command_macros.inc"
event_1B2_command_674A:
    event_wait 0
