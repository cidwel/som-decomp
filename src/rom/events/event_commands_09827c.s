; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $827C
.include "src/rom/event_command_macros.inc"
event_1E5_command_827C:
    event_wait 0
