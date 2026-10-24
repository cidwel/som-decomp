; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A72D
.include "src/rom/event_command_macros.inc"
event_278_command_A72D:
    event_wait 0
