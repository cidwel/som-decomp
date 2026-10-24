; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7662
.include "src/rom/event_command_macros.inc"
event_1CE_command_7662:
    event_wait 0
