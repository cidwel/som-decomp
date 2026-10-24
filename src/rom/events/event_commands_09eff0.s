; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EFF0
.include "src/rom/event_command_macros.inc"
event_3E9_command_EFF0:
    event_wait 0
