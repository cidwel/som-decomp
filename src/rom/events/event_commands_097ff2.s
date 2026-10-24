; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7FF2
.include "src/rom/event_command_macros.inc"
event_1DC_command_7FF2:
    event_call 82
