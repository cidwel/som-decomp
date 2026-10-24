; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0D4E
.include "src/rom/event_command_macros.inc"
event_400_command_0D4E:
    event_wait 56
