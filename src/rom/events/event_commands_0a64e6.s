; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $64E6
.include "src/rom/event_command_macros.inc"
event_555_command_64E6:
    event_increment_flag 45
event_555_command_64E8:
    event_jump 1367
event_555_command_64EA:
    event_end 
