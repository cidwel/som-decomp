; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6B84
.include "src/rom/event_command_macros.inc"
event_578_command_6B84:
    event_jump 1535
event_578_command_6B86:
    event_end 
event_579_command_6B87:
    event_end 
event_57A_command_6B88:
    event_end 
event_57B_command_6B89:
    event_end 
event_57C_command_6B8A:
    event_end 
event_57D_command_6B8B:
    event_end 
event_57E_command_6B8C:
    event_end 
event_57F_command_6B8D:
    event_end 
event_580_command_6B8E:
    event_set_actor_field 2, 200, 56
event_580_command_6B92:
    event_set_actor_field 3, 200, 7
event_580_command_6B96:
    event_wait 16
