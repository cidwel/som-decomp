; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2726
.include "src/rom/event_command_macros.inc"
event_103_command_2726:
    event_wait 2
