; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68A4
.include "src/rom/event_command_macros.inc"
event_55E_command_68A4:
    event_wait 32
event_55E_command_68A6:
    event_actor_walk 2, 0, 8
event_55E_command_68A9:
    event_wait_idle 
event_55E_command_68AA:
    event_actor_animation_loop 2, 128
event_55E_command_68AD:
    event_wait_idle 
event_55E_command_68AE:
    event_call 1927
