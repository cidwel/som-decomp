; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A845
.include "src/rom/event_command_macros.inc"
event_27C_command_A845:
    event_wait 16
