; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $45AD
.include "src/rom/event_command_macros.inc"
event_146_command_45AD:
    event_wait 0
