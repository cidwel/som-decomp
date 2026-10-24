; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $151B
.include "src/rom/event_command_macros.inc"
event_42D_command_151B:
    event_wait 16
