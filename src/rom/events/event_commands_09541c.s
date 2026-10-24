; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $541C
.include "src/rom/event_command_macros.inc"
event_173_command_541C:
    event_wait 0
