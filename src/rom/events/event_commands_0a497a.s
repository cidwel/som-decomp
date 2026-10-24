; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $497A
.include "src/rom/event_command_macros.inc"
event_4E9_command_497A:
    event_increment_flag 17
event_4E9_command_497C:
    event_jump 1535
event_4E9_command_497E:
    event_end 
