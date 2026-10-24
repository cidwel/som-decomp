; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8993
.include "src/rom/event_command_macros.inc"
event_65F_command_8993:
    event_wait 0
