; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $500F
.include "src/rom/event_command_macros.inc"
event_16D_command_500F:
    event_wait 0
