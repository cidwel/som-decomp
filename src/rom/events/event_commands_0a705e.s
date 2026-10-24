; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $705E
.include "src/rom/event_command_macros.inc"
event_584_command_705E:
    event_call 1993
event_584_command_7060:
    event_end 
event_585_command_7061:
    event_set_actor_field 2, 205, 24
event_585_command_7065:
    event_set_actor_field 3, 205, 3
