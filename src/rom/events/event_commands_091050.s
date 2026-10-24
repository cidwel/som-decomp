; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1050
.include "src/rom/event_command_macros.inc"
event_041_command_1050:
    event_test_flag_range 198, 0, 0
event_041_command_1053:
    event_increment_flag 198
event_041_command_1055:
    event_return 
event_041_command_1056:
    event_end 
