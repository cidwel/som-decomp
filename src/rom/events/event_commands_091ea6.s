; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1EA6
.include "src/rom/event_command_macros.inc"
event_0E1_command_1EA6:
    event_jump 255
event_0E1_command_1EA8:
    event_jump 231
event_0E1_command_1EAA:
    event_jump 232
event_0E1_command_1EAC:
    event_end 
event_0E2_command_1EAD:
    event_set_flag 15, 0
event_0E2_command_1EB0:
    event_call 1032
