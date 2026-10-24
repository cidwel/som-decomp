; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AC0C
.include "src/rom/event_command_macros.inc"
event_28C_command_AC0C:
    event_wait 0
