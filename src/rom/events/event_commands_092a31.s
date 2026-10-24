; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2A31
.include "src/rom/event_command_macros.inc"
event_106_command_2A31:
    event_wait 0
