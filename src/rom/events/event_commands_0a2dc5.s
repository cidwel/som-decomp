; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2DC5
.include "src/rom/event_command_macros.inc"
event_4E1_command_2DC5:
    event_wait 32
