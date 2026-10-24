; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $65D9
.include "src/rom/event_command_macros.inc"
event_558_command_65D9:
    event_set_actor_field 4, 144, 0
event_558_command_65DD:
    event_actor_animation 4, 128
event_558_command_65E0:
    event_wait_idle 
event_558_command_65E1:
    event_screen 7
event_558_command_65E3:
    event_wait 16
