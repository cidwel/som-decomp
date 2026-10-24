; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8145
.include "src/rom/event_command_macros.inc"
event_5F8_command_8145:
    event_call 2008
event_5F8_command_8147:
    event_actor_animation_loop 1, 167
event_5F8_command_814A:
    event_wait_idle 
event_5F8_command_814B:
    event_wait 0
