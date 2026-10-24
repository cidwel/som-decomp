; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9B84
.include "src/rom/event_command_macros.inc"
event_235_command_9B84:
    event_decrement_flag 255
event_235_command_9B86:
    event_end 
event_236_command_9B87:
    event_increment_flag 24
event_236_command_9B89:
    event_call 1150
