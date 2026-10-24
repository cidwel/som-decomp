; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2DC8
.include "src/rom/event_command_macros.inc"
event_4E1_command_2DC8:
    event_increment_flag 78
event_4E1_command_2DCA:
    event_refresh_objects 
event_4E1_command_2DCB:
    event_wait 32
event_4E1_command_2DCD:
    event_call 2008
event_4E1_command_2DCF:
    event_actor_walk 2, 2, 0
event_4E1_command_2DD2:
    event_wait_idle 
