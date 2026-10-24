; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EDC0
.include "src/rom/event_command_macros.inc"
event_3DD_command_EDC0:
    event_set_flag 63, 1
event_3DD_command_EDC3:
    event_refresh_objects 
event_3DD_command_EDC4:
    event_screen 8
event_3DD_command_EDC6:
    event_wait 32
event_3DD_command_EDC8:
    event_jump 36
event_3DD_command_EDCA:
    event_end 
event_3DE_command_EDCB:
    event_actor_walk 0, 1, 0
event_3DE_command_EDCE:
    event_wait_idle 
event_3DE_command_EDCF:
    event_increment_flag 248
