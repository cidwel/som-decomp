; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C82C
.include "src/rom/event_command_macros.inc"
event_2ED_command_C82C:
    event_jump 1535
event_2ED_command_C82E:
    event_end 
