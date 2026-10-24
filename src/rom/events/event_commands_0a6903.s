; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6903
.include "src/rom/event_command_macros.inc"
event_55E_command_6903:
    event_actor_walk 2, 1, 0
event_55E_command_6906:
    event_wait_idle 
event_55E_command_6907:
    event_actor_animation_loop 2, 167
event_55E_command_690A:
    event_wait_idle 
event_55E_command_690B:
    event_wait 16
event_55E_command_690D:
    event_wait 0
