; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $218C
.include "src/rom/event_command_macros.inc"
event_4B3_command_218C:
    event_decrement_flag 255
event_4B3_command_218E:
    event_end 
event_4B4_command_218F:
    event_call 1283
event_4B4_command_2191:
    event_increment_flag 69
event_4B4_command_2193:
    event_set_flag 151, 2
event_4B4_command_2196:
    event_increment_flag 248
