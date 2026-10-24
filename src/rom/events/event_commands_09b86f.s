; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B86F
.include "src/rom/event_command_macros.inc"
event_2B1_command_B86F:
    event_wait 0
