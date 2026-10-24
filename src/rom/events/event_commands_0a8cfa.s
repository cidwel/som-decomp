; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8CFA
.include "src/rom/event_command_macros.inc"
event_66D_command_8CFA:
    event_wait 0
