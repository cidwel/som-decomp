; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1BAB
.include "src/rom/event_command_macros.inc"
event_4AA_command_1BAB:
    event_wait 0
