; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DBDD
.include "src/rom/event_command_macros.inc"
event_38D_command_DBDD:
    event_wait 0
