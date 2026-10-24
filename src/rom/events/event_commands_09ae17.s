; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AE17
.include "src/rom/event_command_macros.inc"
event_291_command_AE17:
    event_wait 0
