; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0EB5
.include "src/rom/event_command_macros.inc"
event_030_command_0EB5:
    event_wait 32
event_030_command_0EB7:
    event_actor_walk 128, 1, 0
event_030_command_0EBA:
    event_wait_idle 
event_030_command_0EBB:
    event_wait 16
event_030_command_0EBD:
    event_call 89
event_030_command_0EBF:
    event_jump 47
event_030_command_0EC1:
    event_end 
