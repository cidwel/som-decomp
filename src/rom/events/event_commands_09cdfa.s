; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CDFA
.include "src/rom/event_command_macros.inc"
event_319_command_CDFA:
    event_call 1152
