; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0DF3
.include "src/rom/event_command_macros.inc"
event_030_command_0DF3:
    event_wait 0
