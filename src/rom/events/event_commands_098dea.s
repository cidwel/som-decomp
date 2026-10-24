; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8DEA
.include "src/rom/event_command_macros.inc"
event_202_command_8DEA:
    event_wait 0
