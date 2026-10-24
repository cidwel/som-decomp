; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8F04
.include "src/rom/event_command_macros.inc"
event_687_command_8F04:
    event_call 1984
event_687_command_8F06:
    event_wait 0
