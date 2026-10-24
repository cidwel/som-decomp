; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B91E
.include "src/rom/event_command_macros.inc"
event_2B2_command_B91E:
    event_wait 0
