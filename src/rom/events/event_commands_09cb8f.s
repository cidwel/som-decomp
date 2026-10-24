; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CB8F
.include "src/rom/event_command_macros.inc"
event_2FD_command_CB8F:
    event_actor_animation 3, 170
event_2FD_command_CB92:
    event_wait_idle 
event_2FD_command_CB93:
    event_jump 725
event_2FD_command_CB95:
    event_end 
event_2FE_command_CB96:
    event_wait 0
