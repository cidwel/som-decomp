; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7A49
.include "src/rom/event_command_macros.inc"
event_5F8_command_7A49:
    event_wait 32
