; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AE4E
.include "src/rom/event_command_macros.inc"
event_292_command_AE4E:
    event_wait 0
