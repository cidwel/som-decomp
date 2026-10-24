; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1AFC
.include "src/rom/event_command_macros.inc"
event_4A4_command_1AFC:
    event_call 1189
