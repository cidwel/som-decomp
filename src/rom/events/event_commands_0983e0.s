; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $83E0
.include "src/rom/event_command_macros.inc"
event_1E7_command_83E0:
    event_wait 16
event_1E7_command_83E2:
    event_increment_flag 23
event_1E7_command_83E4:
    event_refresh_objects 
event_1E7_command_83E5:
    event_wait 4
event_1E7_command_83E7:
    event_decrement_flag 23
event_1E7_command_83E9:
    event_refresh_objects 
event_1E7_command_83EA:
    event_wait 3
event_1E7_command_83EC:
    event_increment_flag 23
event_1E7_command_83EE:
    event_refresh_objects 
event_1E7_command_83EF:
    event_wait 2
event_1E7_command_83F1:
    event_decrement_flag 23
event_1E7_command_83F3:
    event_refresh_objects 
event_1E7_command_83F4:
    event_wait 1
event_1E7_command_83F6:
    event_increment_flag 23
event_1E7_command_83F8:
    event_refresh_objects 
event_1E7_command_83F9:
    event_wait 16
event_1E7_command_83FB:
    event_actor_walk 4, 0, 4
event_1E7_command_83FE:
    event_wait_idle 
event_1E7_command_83FF:
    event_actor_walk 2, 0, 8
event_1E7_command_8402:
    event_wait_idle 
