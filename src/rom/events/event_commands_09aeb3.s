; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AEB3
.include "src/rom/event_command_macros.inc"
event_293_command_AEB3:
    event_wait 0
