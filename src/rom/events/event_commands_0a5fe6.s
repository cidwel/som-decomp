; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FE6
.include "src/rom/event_command_macros.inc"
event_52F_command_5FE6:
    event_wait 0
