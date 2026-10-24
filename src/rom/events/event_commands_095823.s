; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5823
.include "src/rom/event_command_macros.inc"
event_182_command_5823:
    event_wait 0
