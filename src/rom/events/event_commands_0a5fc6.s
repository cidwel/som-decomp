; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FC6
.include "src/rom/event_command_macros.inc"
event_52F_command_5FC6:
    event_wait 0
