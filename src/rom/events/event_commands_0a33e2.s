; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $33E2
.include "src/rom/event_command_macros.inc"
event_4E2_command_33E2:
    event_wait 0
