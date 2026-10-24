; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7088
.include "src/rom/event_command_macros.inc"
event_585_command_7088:
    event_return 
event_585_command_7089:
    event_end 
event_586_command_708A:
    event_set_actor_field 2, 206, 0
event_586_command_708E:
    event_set_actor_field 3, 206, 7
