; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8BF9
.include "src/rom/event_command_macros.inc"
event_1FD_command_8BF9:
    event_set_flag 4, 3
event_1FD_command_8BFC:
    event_jump 1535
event_1FD_command_8BFE:
    event_end 
