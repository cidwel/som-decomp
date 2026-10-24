; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B5F
.include "src/rom/event_command_macros.inc"
event_1F6_command_8B5F:
    event_jump 1535
event_1F6_command_8B61:
    event_end 
event_1F7_command_8B62:
    event_end 
event_1F8_command_8B63:
    event_end 
event_1F9_command_8B64:
    event_end 
event_1FA_command_8B65:
    event_end 
event_1FB_command_8B66:
    event_end 
event_1FC_command_8B67:
    event_end 
event_1FD_command_8B68:
    event_actor_animation_loop 2, 128
event_1FD_command_8B6B:
    event_wait_idle 
