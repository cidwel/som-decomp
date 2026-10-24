; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2ECF
.include "src/rom/event_command_macros.inc"
event_10C_command_2ECF:
    event_wait 0
