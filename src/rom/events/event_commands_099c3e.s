; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9C3E
.include "src/rom/event_command_macros.inc"
event_236_command_9C3E:
    event_call 1925
event_236_command_9C40:
    event_screen 2
event_236_command_9C42:
    event_wait 8
event_236_command_9C44:
    event_screen 8
