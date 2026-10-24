; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7568
.include "src/rom/event_command_macros.inc"
event_1CC_command_7568:
    event_wait 0
