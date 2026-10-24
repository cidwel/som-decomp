; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EDF7
.include "src/rom/event_command_macros.inc"
event_3DE_command_EDF7:
    event_decrement_flag 248
event_3DE_command_EDF9:
    event_actor_animation 0, 140
event_3DE_command_EDFC:
    event_wait_idle 
event_3DE_command_EDFD:
    event_end 
event_3DF_command_EDFE:
    event_jump 1253
event_3DF_command_EE00:
    event_end 
event_3E0_command_EE01:
    event_jump 1797
event_3E0_command_EE03:
    event_end 
event_3E1_command_EE04:
    event_jump 1797
event_3E1_command_EE06:
    event_end 
