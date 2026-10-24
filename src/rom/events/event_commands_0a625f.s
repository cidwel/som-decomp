; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $625F
.include "src/rom/event_command_macros.inc"
event_543_command_625F:
    event_wait 0
