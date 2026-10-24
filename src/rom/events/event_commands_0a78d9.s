; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $78D9
.include "src/rom/event_command_macros.inc"
event_5DA_command_78D9:
    event_jump 1497
event_5DA_command_78DB:
    event_jump 1496
event_5DA_command_78DD:
    event_jump 1497
event_5DA_command_78DF:
    event_end 
event_5DB_command_78E0:
    event_increment_flag 248
