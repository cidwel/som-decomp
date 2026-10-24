; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8426
.include "src/rom/event_command_macros.inc"
event_5F8_command_8426:
    event_actor_walk 3, 2, 0
event_5F8_command_8429:
    event_wait_idle 
event_5F8_command_842A:
    event_wait 32
event_5F8_command_842C:
    event_actor_walk 1, 3, 0
event_5F8_command_842F:
    event_wait_idle 
event_5F8_command_8430:
    event_wait 16
event_5F8_command_8432:
    event_actor_walk 1, 2, 0
event_5F8_command_8435:
    event_wait_idle 
event_5F8_command_8436:
    event_wait 16
