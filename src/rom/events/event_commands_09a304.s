; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A304
.include "src/rom/event_command_macros.inc"
event_263_command_A304:
    event_wait 0
