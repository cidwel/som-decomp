; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F56
.include "src/rom/event_command_macros.inc"
event_582_command_6F56:
    event_wait 16
event_582_command_6F58:
    event_wait 0
