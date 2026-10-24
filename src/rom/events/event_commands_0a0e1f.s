; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E1F
.include "src/rom/event_command_macros.inc"
event_400_command_0E1F:
    event_wait 16
