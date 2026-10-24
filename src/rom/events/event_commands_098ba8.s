; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8BA8
.include "src/rom/event_command_macros.inc"
event_1FD_command_8BA8:
    event_wait 0
