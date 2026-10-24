; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $70D5
.include "src/rom/event_command_macros.inc"
event_586_command_70D5:
    event_wait 0
