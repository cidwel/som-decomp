; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7725
.include "src/rom/event_command_macros.inc"
event_59B_command_7725:
    event_wait 0
