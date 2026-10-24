; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $27ED
.include "src/rom/event_command_macros.inc"
event_4D0_command_27ED:
    event_wait 0
