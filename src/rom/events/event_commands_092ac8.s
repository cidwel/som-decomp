; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2AC8
.include "src/rom/event_command_macros.inc"
event_106_command_2AC8:
    event_actor_walk 5, 2, 63
event_106_command_2ACB:
    event_actor_walk 6, 2, 63
event_106_command_2ACE:
    event_actor_animation 0, 160
event_106_command_2AD1:
    event_wait 12
event_106_command_2AD3:
    event_actor_walk 5, 1, 2
event_106_command_2AD6:
    event_actor_walk 6, 1, 2
event_106_command_2AD9:
    event_call 1864
