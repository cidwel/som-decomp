; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $699F
.include "src/rom/event_command_macros.inc"
event_1B5_command_699F:
    event_wait 0
