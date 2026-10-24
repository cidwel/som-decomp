; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $672E
.include "src/rom/event_command_macros.inc"
event_559_command_672E:
    event_wait 32
event_559_command_6730:
    event_actor_walk 1, 1, 8
event_559_command_6733:
    event_actor_walk 3, 1, 8
event_559_command_6736:
    event_wait_idle 
event_559_command_6737:
    event_actor_walk 1, 2, 0
event_559_command_673A:
    event_actor_walk 3, 3, 0
event_559_command_673D:
    event_wait_idle 
