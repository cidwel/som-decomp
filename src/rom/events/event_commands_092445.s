; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2445
.include "src/rom/event_command_macros.inc"
event_0FB_command_2445:
    event_wait 0
