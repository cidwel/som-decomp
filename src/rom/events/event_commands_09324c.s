; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $324C
.include "src/rom/event_command_macros.inc"
event_10E_command_324C:
    event_jump 1535
event_10E_command_324E:
    event_end 
event_10F_command_324F:
    event_test_flag_range 16, 4, 9
event_10F_command_3252:
    event_jump 211
event_10F_command_3254:
    event_test_flag_range 16, 10, 15
event_10F_command_3257:
    event_jump 277
