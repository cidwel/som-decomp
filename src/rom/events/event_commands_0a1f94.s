; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F94
.include "src/rom/event_command_macros.inc"
event_4B3_command_1F94:
    event_wait 0
