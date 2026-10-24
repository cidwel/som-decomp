; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B397
.include "src/rom/event_command_macros.inc"
event_29E_command_B397:
    event_wait 0
