; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7687
.include "src/rom/event_command_macros.inc"
event_59B_command_7687:
    event_wait 0
