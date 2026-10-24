; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8FA5
.include "src/rom/event_command_macros.inc"
event_204_command_8FA5:
    event_wait 0
