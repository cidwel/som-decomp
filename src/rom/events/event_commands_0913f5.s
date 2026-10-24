; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $13F5
.include "src/rom/event_command_macros.inc"
event_083_command_13F5:
    event_jump 132
event_083_command_13F7:
    event_end 
event_084_command_13F8:
    event_actor_walk 5, 0, 0
event_084_command_13FB:
    event_wait_idle 
event_084_command_13FC:
    event_set_flag 144, 2
event_084_command_13FF:
    event_refresh_objects 
event_084_command_1400:
    event_wait 24
