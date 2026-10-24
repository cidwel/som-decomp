; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A46D
.include "src/rom/event_command_macros.inc"
event_267_command_A46D:
    event_actor_walk 128, 0, 16
event_267_command_A470:
    event_wait_idle 
event_267_command_A471:
    event_actor_walk 128, 1, 0
event_267_command_A474:
    event_wait_idle 
event_267_command_A475:
    event_jump 574
event_267_command_A477:
    event_end 
