; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DA7E
.include "src/rom/event_command_macros.inc"
event_38C_command_DA7E:
    event_wait 24
