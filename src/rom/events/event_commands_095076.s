; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5076
.include "src/rom/event_command_macros.inc"
event_16D_command_5076:
    event_actor_walk 1, 0, 16
event_16D_command_5079:
    event_actor_walk 2, 0, 16
event_16D_command_507C:
    event_actor_walk 3, 0, 16
event_16D_command_507F:
    event_wait_idle 
event_16D_command_5080:
    event_call 1152
event_16D_command_5082:
    event_wait 0
