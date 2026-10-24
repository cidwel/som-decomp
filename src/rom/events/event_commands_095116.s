; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5116
.include "src/rom/event_command_macros.inc"
event_16D_command_5116:
    event_wait 0
