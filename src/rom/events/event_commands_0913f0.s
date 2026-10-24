; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $13F0
.include "src/rom/event_command_macros.inc"
event_083_command_13F0:
    event_screen 8
event_083_command_13F2:
    event_wait 0
