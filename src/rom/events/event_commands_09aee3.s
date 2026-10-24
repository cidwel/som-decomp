; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AEE3
.include "src/rom/event_command_macros.inc"
event_293_command_AEE3:
    event_wait 0
