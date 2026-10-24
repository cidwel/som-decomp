; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2CDA
.include "src/rom/event_command_macros.inc"
event_4E1_command_2CDA:
    event_actor_walk 5, 0, 2
event_4E1_command_2CDD:
    event_wait_idle 
event_4E1_command_2CDE:
    event_wait 4
event_4E1_command_2CE0:
    event_actor_walk 5, 0, 2
event_4E1_command_2CE3:
    event_wait_idle 
event_4E1_command_2CE4:
    event_wait 4
event_4E1_command_2CE6:
    event_actor_walk 5, 0, 2
event_4E1_command_2CE9:
    event_wait_idle 
event_4E1_command_2CEA:
    event_wait 4
event_4E1_command_2CEC:
    event_actor_walk 5, 0, 2
event_4E1_command_2CEF:
    event_wait_idle 
event_4E1_command_2CF0:
    event_wait 4
event_4E1_command_2CF2:
    event_actor_walk 5, 2, 0
event_4E1_command_2CF5:
    event_wait_idle 
event_4E1_command_2CF6:
    event_wait 16
