; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6580
.include "src/rom/event_command_macros.inc"
event_1B0_command_6580:
    event_wait 0
