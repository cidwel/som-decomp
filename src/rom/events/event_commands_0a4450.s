; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4450
.include "src/rom/event_command_macros.inc"
event_4E8_command_4450:
    event_call 301
event_4E8_command_4452:
    event_actor_walk 0, 0, 0
event_4E8_command_4455:
    event_wait_idle 
event_4E8_command_4456:
    event_wait 4
event_4E8_command_4458:
    event_screen 8
event_4E8_command_445A:
    event_actor_animation 4, 139
event_4E8_command_445D:
    event_wait_idle 
