; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2CD7
.include "src/rom/event_command_macros.inc"
event_4E1_command_2CD7:
    event_wait 0
