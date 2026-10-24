; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $437B
.include "src/rom/event_command_macros.inc"
event_4E8_command_437B:
    event_call 1864
