; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DD0F
.include "src/rom/event_command_macros.inc"
event_396_command_DD0F:
    event_jump 1535
event_396_command_DD11:
    event_end 
event_397_command_DD12:
    event_increment_flag 48
event_397_command_DD14:
    event_set_flag 55, 1
