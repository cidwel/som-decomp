; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7214
.include "src/rom/event_command_macros.inc"
event_587_command_7214:
    event_screen 7
event_587_command_7216:
    event_set_actor_field 2, 207, 56
event_587_command_721A:
    event_set_actor_field 3, 207, 0
event_587_command_721E:
    event_increment_flag 172
event_587_command_7220:
    event_refresh_objects 
event_587_command_7221:
    event_wait 1
event_587_command_7223:
    event_decrement_flag 172
event_587_command_7225:
    event_refresh_objects 
event_587_command_7226:
    event_wait 1
event_587_command_7228:
    event_increment_flag 172
event_587_command_722A:
    event_refresh_objects 
event_587_command_722B:
    event_wait 1
event_587_command_722D:
    event_decrement_flag 172
event_587_command_722F:
    event_refresh_objects 
event_587_command_7230:
    event_wait 1
event_587_command_7232:
    event_increment_flag 172
event_587_command_7234:
    event_refresh_objects 
event_587_command_7235:
    event_wait 16
