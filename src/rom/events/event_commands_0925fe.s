; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $25FE
.include "src/rom/event_command_macros.inc"
event_102_command_25FE:
    event_wait 4
event_102_command_2600:
    event_screen 7
event_102_command_2602:
    event_wait 4
