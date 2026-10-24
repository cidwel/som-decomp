; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B8F5
.include "src/rom/event_command_macros.inc"
event_2B2_command_B8F5:
    event_wait 0
