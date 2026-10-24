; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5BC2
.include "src/rom/event_command_macros.inc"
event_18A_command_5BC2:
    event_wait 0
