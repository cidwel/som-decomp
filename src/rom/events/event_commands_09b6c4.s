; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B6C4
.include "src/rom/event_command_macros.inc"
event_2AE_command_B6C4:
    event_wait 0
