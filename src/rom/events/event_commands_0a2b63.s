; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2B63
.include "src/rom/event_command_macros.inc"
event_4E0_command_2B63:
    event_call 83
event_4E0_command_2B65:
    event_wait 16
event_4E0_command_2B67:
    event_call 86
event_4E0_command_2B69:
    event_wait 16
event_4E0_command_2B6B:
    event_call 82
event_4E0_command_2B6D:
    event_jump 45
event_4E0_command_2B6F:
    event_end 
event_4E1_command_2B70:
    event_freeze 
event_4E1_command_2B71:
    event_call 2007
event_4E1_command_2B73:
    event_actor_walk 0, 0, 40
event_4E1_command_2B76:
    event_wait_idle 
event_4E1_command_2B77:
    event_call 1150
