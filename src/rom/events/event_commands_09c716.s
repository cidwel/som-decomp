; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C716
.include "src/rom/event_command_macros.inc"
event_2E8_command_C716:
    event_wait 0
