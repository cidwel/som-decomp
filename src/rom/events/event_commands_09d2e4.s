; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D2E4
.include "src/rom/event_command_macros.inc"
event_365_command_D2E4:
    event_wait 0
