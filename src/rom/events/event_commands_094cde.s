; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4CDE
.include "src/rom/event_command_macros.inc"
event_167_command_4CDE:
    event_wait 16
event_167_command_4CE0:
    event_call 1927
event_167_command_4CE2:
    event_actor_walk 1, 2, 0
event_167_command_4CE5:
    event_actor_animation 2, 140
event_167_command_4CE8:
    event_actor_walk 3, 3, 0
event_167_command_4CEB:
    event_wait_idle 
