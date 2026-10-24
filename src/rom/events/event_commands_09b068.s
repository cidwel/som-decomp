; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B068
.include "src/rom/event_command_macros.inc"
event_29B_command_B068:
    event_wait 0
