; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B737
.include "src/rom/event_command_macros.inc"
event_2AF_command_B737:
    event_wait 0
