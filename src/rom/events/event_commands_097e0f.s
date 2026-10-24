; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7E0F
.include "src/rom/event_command_macros.inc"
event_1DA_command_7E0F:
    event_wait 0
