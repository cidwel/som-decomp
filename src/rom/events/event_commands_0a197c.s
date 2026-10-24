; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $197C
.include "src/rom/event_command_macros.inc"
event_4A1_command_197C:
    event_wait 0
