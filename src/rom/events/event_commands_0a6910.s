; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6910
.include "src/rom/event_command_macros.inc"
event_55E_command_6910:
    event_actor_walk 1, 0, 8
event_55E_command_6913:
    event_actor_walk 3, 0, 8
event_55E_command_6916:
    event_wait_idle 
event_55E_command_6917:
    event_actor_walk 1, 2, 0
event_55E_command_691A:
    event_actor_walk 3, 3, 0
event_55E_command_691D:
    event_wait_idle 
event_55E_command_691E:
    event_wait 16
