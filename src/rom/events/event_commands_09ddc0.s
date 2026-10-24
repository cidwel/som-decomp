; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DDC0
.include "src/rom/event_command_macros.inc"
event_397_command_DDC0:
    event_wait 0
