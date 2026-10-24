; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0CFE
.include "src/rom/event_command_macros.inc"
event_400_command_0CFE:
    event_wait 64
