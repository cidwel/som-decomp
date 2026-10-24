; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0F6D
.include "src/rom/event_command_macros.inc"
event_040_command_0F6D:
    event_wait 0
