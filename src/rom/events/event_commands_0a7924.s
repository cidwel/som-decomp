; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7924
.include "src/rom/event_command_macros.inc"
event_5DB_command_7924:
    event_wait 0
