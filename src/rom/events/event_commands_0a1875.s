; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1875
.include "src/rom/event_command_macros.inc"
event_4A1_command_1875:
    event_call 2007
event_4A1_command_1877:
    event_set_flag 68, 4
event_4A1_command_187A:
    event_refresh_objects 
event_4A1_command_187B:
    event_actor_walk 4, 0, 0
event_4A1_command_187E:
    event_actor_walk 6, 1, 63
event_4A1_command_1881:
    event_wait_idle 
event_4A1_command_1882:
    event_actor_walk 4, 2, 0
event_4A1_command_1885:
    event_actor_walk 6, 1, 16
event_4A1_command_1888:
    event_wait_idle 
