; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E2E0
.include "src/rom/event_command_macros.inc"
event_3AA_command_E2E0:
    event_wait 0
