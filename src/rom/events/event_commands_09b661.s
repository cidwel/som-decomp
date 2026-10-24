; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B661
.include "src/rom/event_command_macros.inc"
event_2AC_command_B661:
    event_end 
