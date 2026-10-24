; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68EB
.include "src/rom/event_command_macros.inc"
event_55E_command_68EB:
    event_actor_walk 2, 3, 0
event_55E_command_68EE:
    event_wait_idle 
