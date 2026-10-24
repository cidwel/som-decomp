; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5194
.include "src/rom/event_command_macros.inc"
event_16D_command_5194:
    event_wait 0
