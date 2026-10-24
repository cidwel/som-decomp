; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3112
.include "src/rom/event_command_macros.inc"
event_10C_command_3112:
    event_wait 8
