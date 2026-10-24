; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B633
.include "src/rom/event_command_macros.inc"
event_2AA_command_B633:
    event_wait 0
