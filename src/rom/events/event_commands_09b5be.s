; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B5BE
.include "src/rom/event_command_macros.inc"
event_2A7_command_B5BE:
    event_jump 0
event_2A7_command_B5C0:
    event_jump 680
event_2A7_command_B5C2:
    event_jump 0
event_2A7_command_B5C4:
    event_end 
event_2A8_command_B5C5:
    event_set_flag 40, 14
event_2A8_command_B5C8:
    event_call 681
event_2A8_command_B5CA:
    event_change_map 404
event_2A8_command_B5CC:
    event_end 
