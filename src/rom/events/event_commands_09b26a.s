; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B26A
.include "src/rom/event_command_macros.inc"
event_29C_command_B26A:
    event_wait 0
