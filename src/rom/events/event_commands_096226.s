; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6226
.include "src/rom/event_command_macros.inc"
event_19F_command_6226:
    event_wait 0
