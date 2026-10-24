; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E22D
.include "src/rom/event_command_macros.inc"
event_3AA_command_E22D:
    event_wait 0
