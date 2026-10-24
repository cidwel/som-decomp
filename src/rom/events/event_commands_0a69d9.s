; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $69D9
.include "src/rom/event_command_macros.inc"
event_55E_command_69D9:
    event_actor_walk 2, 1, 8
event_55E_command_69DC:
    event_wait_idle 
