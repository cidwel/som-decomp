; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $248E
.include "src/rom/event_command_macros.inc"
event_4B6_command_248E:
    event_increment_flag 65
event_4B6_command_2490:
    event_increment_flag 69
event_4B6_command_2492:
    event_set_flag 74, 0
event_4B6_command_2495:
    event_set_flag 75, 0
event_4B6_command_2498:
    event_set_flag 58, 3
event_4B6_command_249B:
    event_increment_flag 53
event_4B6_command_249D:
    event_call 1822
event_4B6_command_249F:
    event_party_command 3
event_4B6_command_24A1:
    event_end 
event_4B7_command_24A2:
    event_set_flag 255, 1
event_4B7_command_24A5:
    event_end 
event_4B8_command_24A6:
    event_increment_flag 68
event_4B8_command_24A8:
    event_call 1287
event_4B8_command_24AA:
    event_set_flag 74, 1
event_4B8_command_24AD:
    event_set_flag 75, 1
event_4B8_command_24B0:
    event_set_flag 76, 0
event_4B8_command_24B3:
    event_call 1932
event_4B8_command_24B5:
    event_redraw_pieces 
event_4B8_command_24B6:
    event_call 2009
event_4B8_command_24B8:
    event_end 
