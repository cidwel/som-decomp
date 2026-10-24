; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $406C
.include "src/rom/event_command_macros.inc"
event_13A_command_406C:
    event_wait 0
