; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D58A
.include "src/rom/event_command_macros.inc"
event_36F_command_D58A:
    event_wait 0
