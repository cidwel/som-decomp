; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B298
.include "src/rom/event_command_macros.inc"
event_29C_command_B298:
    event_increment_flag 40
event_29C_command_B29A:
    event_set_flag 13, 1
event_29C_command_B29D:
    event_refresh_objects 
event_29C_command_B29E:
    event_clone_actor 1
event_29C_command_B2A0:
    event_call 1151
event_29C_command_B2A2:
    event_call 83
event_29C_command_B2A4:
    event_actor_walk 8, 3, 16
event_29C_command_B2A7:
    event_actor_walk 9, 2, 16
event_29C_command_B2AA:
    event_wait_idle 
event_29C_command_B2AB:
    event_actor_walk 8, 0, 32
event_29C_command_B2AE:
    event_actor_walk 9, 0, 32
event_29C_command_B2B1:
    event_wait_idle 
event_29C_command_B2B2:
    event_call 81
event_29C_command_B2B4:
    event_wait 16
event_29C_command_B2B6:
    event_call 1925
event_29C_command_B2B8:
    event_screen 3
event_29C_command_B2BA:
    event_wait 16
