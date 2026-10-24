; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $17F4
.include "src/rom/event_command_macros.inc"
event_0B5_command_17F4:
    event_wait 0
