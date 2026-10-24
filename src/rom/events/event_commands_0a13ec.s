; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $13EC
.include "src/rom/event_command_macros.inc"
event_429_command_13EC:
    event_wait 32
