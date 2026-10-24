; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A933
.include "src/rom/event_command_macros.inc"
event_289_command_A933:
    event_call 88
