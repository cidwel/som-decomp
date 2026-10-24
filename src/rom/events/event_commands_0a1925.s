; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1925
.include "src/rom/event_command_macros.inc"
event_4A1_command_1925:
    event_wait 0
