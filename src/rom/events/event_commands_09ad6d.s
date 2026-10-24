; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AD6D
.include "src/rom/event_command_macros.inc"
event_291_command_AD6D:
    event_wait 0
