; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BD92
.include "src/rom/event_command_macros.inc"
event_2C3_command_BD92:
    event_wait 0
