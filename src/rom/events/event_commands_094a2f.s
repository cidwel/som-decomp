; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4A2F
.include "src/rom/event_command_macros.inc"
event_157_command_4A2F:
    event_wait 0
