; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B60F
.include "src/rom/event_command_macros.inc"
event_2A9_command_B60F:
    event_wait 0
