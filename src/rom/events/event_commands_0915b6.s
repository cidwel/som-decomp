; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $15B6
.include "src/rom/event_command_macros.inc"
event_0AA_command_15B6:
    event_wait 0
