; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68BD
.include "src/rom/event_command_macros.inc"
event_55E_command_68BD:
    event_actor_walk 4, 2, 1
event_55E_command_68C0:
    event_wait_idle 
event_55E_command_68C1:
    event_actor_walk 4, 0, 1
event_55E_command_68C4:
    event_wait_idle 
event_55E_command_68C5:
    event_actor_walk 4, 3, 1
event_55E_command_68C8:
    event_wait_idle 
event_55E_command_68C9:
    event_actor_walk 4, 1, 1
event_55E_command_68CC:
    event_wait_idle 
event_55E_command_68CD:
    event_actor_walk 4, 2, 1
event_55E_command_68D0:
    event_wait_idle 
event_55E_command_68D1:
    event_actor_walk 4, 0, 1
event_55E_command_68D4:
    event_wait_idle 
event_55E_command_68D5:
    event_wait 32
