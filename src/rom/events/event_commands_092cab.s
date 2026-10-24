; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2CAB
.include "src/rom/event_command_macros.inc"
event_10B_command_2CAB:
    event_wait 0
