; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B15A
.include "src/rom/event_command_macros.inc"
event_29C_command_B15A:
    event_increment_flag 40
event_29C_command_B15C:
    event_refresh_objects 
event_29C_command_B15D:
    event_actor_walk 12, 0, 56
event_29C_command_B160:
    event_wait_idle 
event_29C_command_B161:
    event_actor_walk 12, 0, 16
event_29C_command_B164:
    event_wait_idle 
