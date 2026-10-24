; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A4D7
.include "src/rom/event_command_macros.inc"
event_26A_command_A4D7:
    event_wait 0
event_26A_command_A4D9:
    event_actor_walk 5, 3, 0
event_26A_command_A4DC:
    event_wait_idle 
event_26A_command_A4DD:
    event_actor_walk 5, 0, 0
event_26A_command_A4E0:
    event_wait_idle 
event_26A_command_A4E1:
    event_actor_walk 5, 2, 0
event_26A_command_A4E4:
    event_wait_idle 
event_26A_command_A4E5:
    event_actor_walk 5, 1, 0
event_26A_command_A4E8:
    event_wait_idle 
