; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A85
.include "src/rom/event_command_macros.inc"
event_66B_command_8A85:
    event_decrement_flag 248
event_66B_command_8A87:
    event_wait 8
