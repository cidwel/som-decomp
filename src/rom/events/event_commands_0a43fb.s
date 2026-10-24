; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $43FB
.include "src/rom/event_command_macros.inc"
event_4E8_command_43FB:
    event_wait 0
