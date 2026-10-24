; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $444D
.include "src/rom/event_command_macros.inc"
event_4E8_command_444D:
    event_wait 0
