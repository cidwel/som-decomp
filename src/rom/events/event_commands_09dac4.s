; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DAC4
.include "src/rom/event_command_macros.inc"
event_38C_command_DAC4:
    event_jump 0
event_38C_command_DAC6:
    event_jump 909
event_38C_command_DAC8:
    event_jump 0
event_38C_command_DACA:
    event_end 
event_38D_command_DACB:
    event_increment_flag 39
event_38D_command_DACD:
    event_refresh_objects 
event_38D_command_DACE:
    event_screen_word 6, 16
event_38D_command_DAD2:
    event_call 96
event_38D_command_DAD4:
    event_wait 16
event_38D_command_DAD6:
    event_screen 7
event_38D_command_DAD8:
    event_call 1949
event_38D_command_DADA:
    event_increment_flag 39
event_38D_command_DADC:
    event_refresh_objects 
event_38D_command_DADD:
    event_call 2014
event_38D_command_DADF:
    event_call 1410
event_38D_command_DAE1:
    event_increment_flag 39
event_38D_command_DAE3:
    event_refresh_objects 
event_38D_command_DAE4:
    event_audio_request 1, 32, 26, 143
event_38D_command_DAE9:
    event_change_map 322
event_38D_command_DAEB:
    event_actor_walk 1, 0, 20
event_38D_command_DAEE:
    event_actor_walk 2, 0, 12
event_38D_command_DAF1:
    event_wait_idle 
event_38D_command_DAF2:
    event_call 84
