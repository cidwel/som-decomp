; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2DB7
.include "src/rom/event_command_macros.inc"
event_10C_command_2DB7:
    event_actor_walk 0, 3, 0
event_10C_command_2DBA:
    event_actor_walk 4, 2, 0
event_10C_command_2DBD:
    event_actor_walk 5, 0, 0
event_10C_command_2DC0:
    event_wait_idle 
event_10C_command_2DC1:
    event_wait 1
event_10C_command_2DC3:
    event_actor_walk 0, 1, 2
event_10C_command_2DC6:
    event_actor_walk 4, 0, 0
event_10C_command_2DC9:
    event_actor_walk 5, 2, 0
event_10C_command_2DCC:
    event_wait_idle 
event_10C_command_2DCD:
    event_wait 1
event_10C_command_2DCF:
    event_actor_walk 0, 2, 0
event_10C_command_2DD2:
    event_actor_walk 4, 3, 0
event_10C_command_2DD5:
    event_actor_walk 5, 1, 0
event_10C_command_2DD8:
    event_wait_idle 
event_10C_command_2DD9:
    event_wait 1
event_10C_command_2DDB:
    event_actor_walk 0, 0, 0
event_10C_command_2DDE:
    event_actor_walk 4, 1, 0
event_10C_command_2DE1:
    event_wait_idle 
event_10C_command_2DE2:
    event_wait 0
