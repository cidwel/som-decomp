; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3940
.include "src/rom/event_command_macros.inc"
event_121_command_3940:
    event_wait 0
