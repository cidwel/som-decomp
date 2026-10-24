; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7DC9
.include "src/rom/event_command_macros.inc"
event_5F8_command_7DC9:
    event_actor_animation_loop 2, 167
event_5F8_command_7DCC:
    event_wait_idle 
event_5F8_command_7DCD:
    event_wait 0
