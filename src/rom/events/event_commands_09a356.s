; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A356
.include "src/rom/event_command_macros.inc"
event_263_command_A356:
    event_wait 0
