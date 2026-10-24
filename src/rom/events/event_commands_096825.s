; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6825
.include "src/rom/event_command_macros.inc"
event_1B2_command_6825:
    event_set_flag 20, 2
event_1B2_command_6828:
    event_jump 1535
event_1B2_command_682A:
    event_end 
