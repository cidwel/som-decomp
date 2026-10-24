; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2E2D
.include "src/rom/event_command_macros.inc"
event_4E1_command_2E2D:
    event_call 1988
event_4E1_command_2E2F:
    event_wait 0
