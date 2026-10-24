; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6BCA
.include "src/rom/event_command_macros.inc"
event_580_command_6BCA:
    event_jump 1535
event_580_command_6BCC:
    event_end 
event_581_command_6BCD:
    event_actor_walk 4, 0, 8
event_581_command_6BD0:
    event_wait_idle 
event_581_command_6BD1:
    event_call 1151
event_581_command_6BD3:
    event_call 96
