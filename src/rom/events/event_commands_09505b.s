; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $505B
.include "src/rom/event_command_macros.inc"
event_16D_command_505B:
    event_actor_walk 128, 0, 32
event_16D_command_505E:
    event_wait_idle 
event_16D_command_505F:
    event_actor_walk 128, 1, 0
event_16D_command_5062:
    event_wait_idle 
event_16D_command_5063:
    event_wait 8
event_16D_command_5065:
    event_increment_flag 26
event_16D_command_5067:
    event_refresh_objects 
event_16D_command_5068:
    event_wait 16
