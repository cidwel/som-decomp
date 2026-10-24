; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $54D6
.include "src/rom/event_command_macros.inc"
event_173_command_54D6:
    event_wait 16
event_173_command_54D8:
    event_set_flag 18, 9
event_173_command_54DB:
    event_set_flag 19, 7
event_173_command_54DE:
    event_increment_flag 26
event_173_command_54E0:
    event_increment_flag 27
event_173_command_54E2:
    event_increment_flag 21
event_173_command_54E4:
    event_set_flag 144, 15
event_173_command_54E7:
    event_change_map 37
event_173_command_54E9:
    event_jump 1555
event_173_command_54EB:
    event_end 
