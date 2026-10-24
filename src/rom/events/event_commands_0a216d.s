; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $216D
.include "src/rom/event_command_macros.inc"
event_4B3_command_216D:
    event_wait 0
