; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $67D9
.include "src/rom/event_command_macros.inc"
event_1B2_command_67D9:
    event_wait 0
