; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AEE6
.include "src/rom/event_command_macros.inc"
event_293_command_AEE6:
    event_actor_walk 0, 2, 0
event_293_command_AEE9:
    event_wait_idle 
event_293_command_AEEA:
    event_actor_animation 0, 141
event_293_command_AEED:
    event_wait_idle 
event_293_command_AEEE:
    event_increment_flag 40
event_293_command_AEF0:
    event_refresh_objects 
event_293_command_AEF1:
    event_end 
