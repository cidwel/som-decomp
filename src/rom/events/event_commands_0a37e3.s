; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $37E3
.include "src/rom/event_command_macros.inc"
event_4E3_command_37E3:
    event_wait 0
