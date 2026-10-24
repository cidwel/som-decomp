; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A06C
.include "src/rom/event_command_macros.inc"
event_250_command_A06C:
    event_jump 1796
event_250_command_A06E:
    event_end 
event_251_command_A06F:
    event_call 1286
event_251_command_A071:
    event_increment_flag 34
event_251_command_A073:
    event_set_flag 33, 3
event_251_command_A076:
    event_refresh_objects 
event_251_command_A077:
    event_redraw_pieces 
event_251_command_A078:
    event_call 1995
event_251_command_A07A:
    event_end 
event_252_command_A07B:
    event_jump 1250
event_252_command_A07D:
    event_end 
event_253_command_A07E:
    event_actor_walk 128, 3, 0
event_253_command_A081:
    event_wait_idle 
