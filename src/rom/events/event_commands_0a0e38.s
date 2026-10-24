; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E38
.include "src/rom/event_command_macros.inc"
event_400_command_0E38:
    event_wait 48
