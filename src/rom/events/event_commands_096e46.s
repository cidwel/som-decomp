; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E46
.include "src/rom/event_command_macros.inc"
event_1B9_command_6E46:
    event_wait 0
