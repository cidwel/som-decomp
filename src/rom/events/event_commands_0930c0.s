; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $30C0
.include "src/rom/event_command_macros.inc"
event_10C_command_30C0:
    event_wait 8
