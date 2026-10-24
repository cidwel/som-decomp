; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F245
.include "src/rom/event_command_macros.inc"
event_3EF_command_F245:
    event_wait 0
