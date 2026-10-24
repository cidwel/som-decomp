; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CBDE
.include "src/rom/event_command_macros.inc"
event_2FE_command_CBDE:
    event_wait 0
