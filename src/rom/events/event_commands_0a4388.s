; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4388
.include "src/rom/event_command_macros.inc"
event_4E8_command_4388:
    event_actor_walk 6, 1, 0
event_4E8_command_438B:
    event_wait_idle 
event_4E8_command_438C:
    event_wait 1
event_4E8_command_438E:
    event_actor_walk 6, 3, 0
event_4E8_command_4391:
    event_wait_idle 
event_4E8_command_4392:
    event_wait 1
event_4E8_command_4394:
    event_actor_walk 6, 0, 0
event_4E8_command_4397:
    event_wait_idle 
event_4E8_command_4398:
    event_wait 1
event_4E8_command_439A:
    event_actor_walk 6, 2, 0
event_4E8_command_439D:
    event_wait_idle 
event_4E8_command_439E:
    event_wait 8
