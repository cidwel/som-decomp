; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8DD2
.include "src/rom/event_command_macros.inc"
event_66D_command_8DD2:
    event_wait 0
