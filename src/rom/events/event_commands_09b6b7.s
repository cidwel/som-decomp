; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B6B7
.include "src/rom/event_command_macros.inc"
event_2AE_command_B6B7:
    event_wait 16
