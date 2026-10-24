; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $411D
.include "src/rom/event_command_macros.inc"
event_4E6_command_411D:
    event_increment_flag 16
event_4E6_command_411F:
    event_jump 1535
event_4E6_command_4121:
    event_end 
event_4E7_command_4122:
    event_call 1864
event_4E7_command_4124:
    event_increment_flag 9
