; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $14DF
.include "src/rom/event_command_macros.inc"
event_084_command_14DF:
    event_wait 0
