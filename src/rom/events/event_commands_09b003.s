; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B003
.include "src/rom/event_command_macros.inc"
event_299_command_B003:
    event_wait 0
