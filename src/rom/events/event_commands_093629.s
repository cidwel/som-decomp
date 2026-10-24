; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3629
.include "src/rom/event_command_macros.inc"
event_112_command_3629:
    event_wait 0
