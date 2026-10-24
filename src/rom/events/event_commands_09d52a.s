; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D52A
.include "src/rom/event_command_macros.inc"
event_36F_command_D52A:
    event_wait 0
