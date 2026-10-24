; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $45CF
.include "src/rom/event_command_macros.inc"
event_146_command_45CF:
    event_wait 16
