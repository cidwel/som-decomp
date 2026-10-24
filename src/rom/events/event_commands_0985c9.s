; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85C9
.include "src/rom/event_command_macros.inc"
event_1E7_command_85C9:
    event_wait 0
