; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8D19
.include "src/rom/event_command_macros.inc"
event_200_command_8D19:
    event_end 
event_200_command_8D1A:
    event_end 
event_200_command_8D1B:
    event_jump 513
event_200_command_8D1D:
    event_increment_flag 10
event_200_command_8D1F:
    event_jump 515
event_200_command_8D21:
    event_end 
