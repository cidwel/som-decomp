; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CABF
.include "src/rom/event_command_macros.inc"
event_2FC_command_CABF:
    event_wait 0
