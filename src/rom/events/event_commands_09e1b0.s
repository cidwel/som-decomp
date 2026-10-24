; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E1B0
.include "src/rom/event_command_macros.inc"
event_3AA_command_E1B0:
    event_wait 0
