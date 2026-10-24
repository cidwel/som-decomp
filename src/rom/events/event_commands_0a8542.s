; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8542
.include "src/rom/event_command_macros.inc"
event_5F8_command_8542:
    event_actor_animation 1, 170
event_5F8_command_8545:
    event_actor_animation 2, 170
event_5F8_command_8548:
    event_actor_animation 3, 170
event_5F8_command_854B:
    event_wait_idle 
