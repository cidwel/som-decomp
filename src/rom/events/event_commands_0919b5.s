; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19B5
.include "src/rom/event_command_macros.inc"
event_0BC_command_19B5:
    event_wait 0
