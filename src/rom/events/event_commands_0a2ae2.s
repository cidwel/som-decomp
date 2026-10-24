; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2AE2
.include "src/rom/event_command_macros.inc"
event_4E0_command_2AE2:
    event_wait 0
