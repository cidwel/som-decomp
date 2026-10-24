; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9D75
.include "src/rom/event_command_macros.inc"
event_23C_command_9D75:
    event_wait 0
