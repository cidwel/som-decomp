; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8F2F
.include "src/rom/event_command_macros.inc"
event_689_command_8F2F:
    event_call 2004
event_689_command_8F31:
    event_wait 0
