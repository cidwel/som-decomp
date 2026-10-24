; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $63EE
.include "src/rom/event_command_macros.inc"
event_555_command_63EE:
    event_wait 0
