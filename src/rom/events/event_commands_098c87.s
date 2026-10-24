; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8C87
.include "src/rom/event_command_macros.inc"
event_1FE_command_8C87:
    event_wait 0
