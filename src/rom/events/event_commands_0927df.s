; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $27DF
.include "src/rom/event_command_macros.inc"
event_103_command_27DF:
    event_call 95
