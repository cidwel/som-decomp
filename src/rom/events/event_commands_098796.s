; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8796
.include "src/rom/event_command_macros.inc"
event_1ED_command_8796:
    event_audio_request 2, 135, 15, 136
event_1ED_command_879B:
    event_increment_flag 23
event_1ED_command_879D:
    event_refresh_objects 
event_1ED_command_879E:
    event_wait 1
event_1ED_command_87A0:
    event_decrement_flag 23
event_1ED_command_87A2:
    event_refresh_objects 
event_1ED_command_87A3:
    event_wait 1
event_1ED_command_87A5:
    event_increment_flag 23
event_1ED_command_87A7:
    event_refresh_objects 
event_1ED_command_87A8:
    event_wait 1
event_1ED_command_87AA:
    event_decrement_flag 23
event_1ED_command_87AC:
    event_refresh_objects 
event_1ED_command_87AD:
    event_wait 1
event_1ED_command_87AF:
    event_increment_flag 23
event_1ED_command_87B1:
    event_refresh_objects 
event_1ED_command_87B2:
    event_wait 1
event_1ED_command_87B4:
    event_decrement_flag 23
event_1ED_command_87B6:
    event_refresh_objects 
event_1ED_command_87B7:
    event_wait 1
event_1ED_command_87B9:
    event_increment_flag 23
event_1ED_command_87BB:
    event_refresh_objects 
