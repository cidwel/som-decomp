; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E01
.include "src/rom/event_command_macros.inc"
event_4AE_command_1E01:
    event_jump 1535
event_4AE_command_1E03:
    event_end 
event_4AF_command_1E04:
    event_set_flag 75, 1
event_4AF_command_1E07:
    event_redraw_pieces 
event_4AF_command_1E08:
    event_jump 1834
event_4AF_command_1E0A:
    event_end 
event_4B0_command_1E0B:
    event_test_flag_range 65, 0, 0
event_4B0_command_1E0E:
    event_jump 1201
event_4B0_command_1E10:
    event_test_flag_range 68, 1, 1
event_4B0_command_1E13:
    event_jump 1207
event_4B0_command_1E15:
    event_test_flag_range 68, 2, 15
event_4B0_command_1E18:
    event_jump 1199
