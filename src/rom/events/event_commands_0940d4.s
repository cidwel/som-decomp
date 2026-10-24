; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $40D4
.include "src/rom/event_command_macros.inc"
event_13A_command_40D4:
    event_wait 0
