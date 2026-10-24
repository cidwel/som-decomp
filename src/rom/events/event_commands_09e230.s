; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E230
.include "src/rom/event_command_macros.inc"
event_3AA_command_E230:
    event_actor_walk 4, 3, 0
event_3AA_command_E233:
    event_wait_idle 
