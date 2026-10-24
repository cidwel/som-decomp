; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ED45
.include "src/rom/event_command_macros.inc"
event_3DC_command_ED45:
    event_jump 0
event_3DC_command_ED47:
    event_jump 986
event_3DC_command_ED49:
    event_jump 0
event_3DC_command_ED4B:
    event_end 
event_3DD_command_ED4C:
    event_freeze 
event_3DD_command_ED4D:
    event_gather 
event_3DD_command_ED4E:
    event_test_flag_range 149, 0, 0
event_3DD_command_ED51:
    event_jump 33
event_3DD_command_ED53:
    event_test_flag_range 148, 0, 0
event_3DD_command_ED56:
    event_jump 34
event_3DD_command_ED58:
    event_test_flag_range 150, 0, 0
event_3DD_command_ED5B:
    event_jump 35
event_3DD_command_ED5D:
    event_test_flag_range 60, 0, 5
event_3DD_command_ED60:
    event_jump 32
event_3DD_command_ED62:
    event_test_flag_range 63, 1, 4
event_3DD_command_ED65:
    event_jump 36
event_3DD_command_ED67:
    event_test_flag_range 63, 6, 15
event_3DD_command_ED6A:
    event_jump 38
