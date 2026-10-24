; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B65E
.include "src/rom/event_command_macros.inc"
event_2AC_command_B65E:
    event_wait 32
