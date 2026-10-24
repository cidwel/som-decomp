; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44F2
.include "src/rom/event_command_macros.inc"
event_143_command_44F2:
    event_wait 0
