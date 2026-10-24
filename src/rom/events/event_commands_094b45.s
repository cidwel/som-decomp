; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4B45
.include "src/rom/event_command_macros.inc"
event_15A_command_4B45:
    event_wait 0
