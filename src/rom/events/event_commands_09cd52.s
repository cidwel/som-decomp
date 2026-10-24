; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CD52
.include "src/rom/event_command_macros.inc"
event_315_command_CD52:
    event_actor_effect_0e 
event_315_command_CD53:
    event_jump 788
event_315_command_CD55:
    event_end 
event_316_command_CD56:
    event_end 
event_317_command_CD57:
    event_end 
event_318_command_CD58:
    event_set_flag 250, 12
