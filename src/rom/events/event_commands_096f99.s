; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F99
.include "src/rom/event_command_macros.inc"
event_1BE_command_6F99:
    event_call 1988
event_1BE_command_6F9B:
    event_decrement_flag 255
event_1BE_command_6F9D:
    event_end 
event_1BF_command_6F9E:
    event_increment_flag 96
event_1BF_command_6FA0:
    event_redraw_pieces 
event_1BF_command_6FA1:
    event_return 
event_1BF_command_6FA2:
    event_end 
