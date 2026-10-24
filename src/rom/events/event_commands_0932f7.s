; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $32F7
.include "src/rom/event_command_macros.inc"
event_111_command_32F7:
    event_jump 1535
event_111_command_32F9:
    event_end 
event_112_command_32FA:
    event_call 1281
event_112_command_32FC:
    event_set_flag 11, 2
