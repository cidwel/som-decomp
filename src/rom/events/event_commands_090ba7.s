; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0BA7
.include "src/rom/event_command_macros.inc"
event_025_command_0BA7:
    event_wait 0
