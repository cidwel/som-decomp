; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ADE4
.include "src/rom/event_command_macros.inc"
event_291_command_ADE4:
    event_wait 0
