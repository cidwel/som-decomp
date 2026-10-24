; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B922
.include "src/rom/event_command_macros.inc"
event_2B2_command_B922:
    event_call 1839
