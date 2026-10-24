; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5CA6
.include "src/rom/event_command_macros.inc"
event_51D_command_5CA6:
    event_wait 48
