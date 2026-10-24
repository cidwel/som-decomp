; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C887
.include "src/rom/event_command_macros.inc"
event_2EF_command_C887:
    event_jump 1535
event_2EF_command_C889:
    event_end 
