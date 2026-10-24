; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B1AB
.include "src/rom/event_command_macros.inc"
event_29C_command_B1AB:
    event_wait 0
