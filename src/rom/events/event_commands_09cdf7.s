; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CDF7
.include "src/rom/event_command_macros.inc"
event_319_command_CDF7:
    event_wait 0
