; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2594
.include "src/rom/event_command_macros.inc"
event_4C8_command_2594:
    event_wait 0
