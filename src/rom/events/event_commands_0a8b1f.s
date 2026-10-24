; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B1F
.include "src/rom/event_command_macros.inc"
event_66D_command_8B1F:
    event_wait 0
