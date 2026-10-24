; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E712
.include "src/rom/event_command_macros.inc"
event_3C4_command_E712:
    event_wait 0
