; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6454
.include "src/rom/event_command_macros.inc"
event_1A5_command_6454:
    event_actor_walk 8, 1, 63
event_1A5_command_6457:
    event_wait_idle 
event_1A5_command_6458:
    event_set_flag 18, 10
event_1A5_command_645B:
    event_refresh_objects 
event_1A5_command_645C:
    event_end 
