; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44B7
.include "src/rom/event_command_macros.inc"
event_4E8_command_44B7:
    event_wait 0
