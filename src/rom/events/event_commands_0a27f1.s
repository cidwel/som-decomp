; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $27F1
.include "src/rom/event_command_macros.inc"
event_4D0_command_27F1:
    event_call 1839
