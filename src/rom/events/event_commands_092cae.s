; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2CAE
.include "src/rom/event_command_macros.inc"
event_10B_command_2CAE:
    event_end 
event_10C_command_2CAF:
    event_set_flag 16, 5
event_10C_command_2CB2:
    event_freeze 
event_10C_command_2CB3:
    event_gather 
event_10C_command_2CB4:
    event_screen 8
event_10C_command_2CB6:
    event_actor_walk 0, 0, 0
event_10C_command_2CB9:
    event_actor_walk 6, 1, 0
