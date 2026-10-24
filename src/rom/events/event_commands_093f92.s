; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3F92
.include "src/rom/event_command_macros.inc"
event_138_command_3F92:
    event_jump 1535
event_138_command_3F94:
    event_end 
event_139_command_3F95:
    event_test_flag_range 24, 8, 15
event_139_command_3F98:
    event_jump 315
