; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2871
.include "src/rom/event_command_macros.inc"
event_4D8_command_2871:
    event_wait 0
