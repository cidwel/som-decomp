; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5C61
.include "src/rom/event_command_macros.inc"
event_51D_command_5C61:
    event_increment_flag 52
event_51D_command_5C63:
    event_refresh_objects 
event_51D_command_5C64:
    event_actor_walk 4, 2, 0
event_51D_command_5C67:
    event_actor_walk 5, 3, 0
event_51D_command_5C6A:
    event_wait_idle 
