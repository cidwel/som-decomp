; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E2B5
.include "src/rom/event_command_macros.inc"
event_3AA_command_E2B5:
    event_wait 0
