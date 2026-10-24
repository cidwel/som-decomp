; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0FAA
.include "src/rom/event_command_macros.inc"
event_040_command_0FAA:
    event_wait 20
event_040_command_0FAC:
    event_wait 0
