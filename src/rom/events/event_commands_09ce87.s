; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE87
.include "src/rom/event_command_macros.inc"
event_327_command_CE87:
    event_jump 817
event_327_command_CE89:
    event_end 
event_328_command_CE8A:
    event_set_flag 249, 8
event_328_command_CE8D:
    event_call 816
