; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $755F
.include "src/rom/event_command_macros.inc"
event_592_command_755F:
    event_actor_animation_loop 1, 166
event_592_command_7562:
    event_wait_idle 
