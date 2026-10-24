; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D3E6
.include "src/rom/event_command_macros.inc"
event_36A_command_D3E6:
    event_wait 0
