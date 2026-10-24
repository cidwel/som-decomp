; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9F71
.include "src/rom/event_command_macros.inc"
event_24C_command_9F71:
    event_wait 0
