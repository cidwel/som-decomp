; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A7D3
.include "src/rom/event_command_macros.inc"
event_278_command_A7D3:
    event_actor_walk 128, 0, 8
event_278_command_A7D6:
    event_wait_idle 
event_278_command_A7D7:
    event_set_flag 36, 10
event_278_command_A7DA:
    event_refresh_objects 
event_278_command_A7DB:
    event_end 
