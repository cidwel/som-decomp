; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AE1A
.include "src/rom/event_command_macros.inc"
event_291_command_AE1A:
    event_increment_flag 40
event_291_command_AE1C:
    event_end 
