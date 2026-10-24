; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $71C2
.include "src/rom/event_command_macros.inc"
event_1C6_command_71C2:
    event_wait 32
