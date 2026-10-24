; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0A02
.include "src/rom/event_command_macros.inc"
event_021_command_0A02:
    event_call 30
