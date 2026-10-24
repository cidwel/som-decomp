; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6615
.include "src/rom/event_command_macros.inc"
event_1B1_command_6615:
    event_wait 0
