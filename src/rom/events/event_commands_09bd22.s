; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BD22
.include "src/rom/event_command_macros.inc"
event_2C2_command_BD22:
    event_jump 1535
event_2C2_command_BD24:
    event_end 
event_2C3_command_BD25:
    event_increment_flag 59
