; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0DFD
.include "src/rom/event_command_macros.inc"
event_400_command_0DFD:
    event_call 1928
