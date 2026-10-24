; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B32D
.include "src/rom/event_command_macros.inc"
event_29C_command_B32D:
    event_wait 0
