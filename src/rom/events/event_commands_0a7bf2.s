; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7BF2
.include "src/rom/event_command_macros.inc"
event_5F8_command_7BF2:
    event_wait 32
