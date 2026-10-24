; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $670E
.include "src/rom/event_command_macros.inc"
event_1B2_command_670E:
    event_wait 0
