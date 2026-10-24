; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B2FD
.include "src/rom/event_command_macros.inc"
event_29C_command_B2FD:
    event_wait 0
