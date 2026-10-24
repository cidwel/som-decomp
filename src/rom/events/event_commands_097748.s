; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7748
.include "src/rom/event_command_macros.inc"
event_1CE_command_7748:
    event_actor_walk 12, 2, 0
event_1CE_command_774B:
    event_wait_idle 
event_1CE_command_774C:
    event_actor_walk 12, 0, 0
event_1CE_command_774F:
    event_wait_idle 
event_1CE_command_7750:
    event_actor_walk 12, 3, 0
event_1CE_command_7753:
    event_wait_idle 
event_1CE_command_7754:
    event_actor_animation 12, 0
event_1CE_command_7757:
    event_wait_idle 
event_1CE_command_7758:
    event_actor_animation 12, 1
