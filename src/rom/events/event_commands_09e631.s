; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E631
.include "src/rom/event_command_macros.inc"
event_3BD_command_E631:
    event_wait 0
