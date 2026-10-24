; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BD58
.include "src/rom/event_command_macros.inc"
event_2C3_command_BD58:
    event_wait 0
