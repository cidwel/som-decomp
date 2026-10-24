; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B3E7
.include "src/rom/event_command_macros.inc"
event_29E_command_B3E7:
    event_wait 0
