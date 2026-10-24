; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $40AC
.include "src/rom/event_command_macros.inc"
event_4E6_command_40AC:
    event_wait 0
