; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $41C3
.include "src/rom/event_command_macros.inc"
event_13C_command_41C3:
    event_wait 0
