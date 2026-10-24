; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2EBB
.include "src/rom/event_command_macros.inc"
event_10C_command_2EBB:
    event_wait 0
