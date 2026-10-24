; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7FBD
.include "src/rom/event_command_macros.inc"
event_1DC_command_7FBD:
    event_wait 0
