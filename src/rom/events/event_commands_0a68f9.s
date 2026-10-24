; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68F9
.include "src/rom/event_command_macros.inc"
event_55E_command_68F9:
    event_actor_walk 2, 2, 0
event_55E_command_68FC:
    event_wait_idle 
event_55E_command_68FD:
    event_wait 32
