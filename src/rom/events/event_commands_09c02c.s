; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C02C
.include "src/rom/event_command_macros.inc"
event_2D4_command_C02C:
    event_set_flag 60, 2
event_2D4_command_C02F:
    event_refresh_objects 
event_2D4_command_C030:
    event_actor_walk 8, 0, 56
event_2D4_command_C033:
    event_wait_idle 
event_2D4_command_C034:
    event_actor_walk 8, 0, 56
event_2D4_command_C037:
    event_wait_idle 
