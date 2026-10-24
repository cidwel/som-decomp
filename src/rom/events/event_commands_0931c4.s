; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $31C4
.include "src/rom/event_command_macros.inc"
event_10C_command_31C4:
    event_wait 0
