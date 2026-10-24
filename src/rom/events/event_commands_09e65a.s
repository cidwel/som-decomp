; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E65A
.include "src/rom/event_command_macros.inc"
event_3BD_command_E65A:
    event_jump 1535
event_3BD_command_E65C:
    event_end 
event_3BE_command_E65D:
    event_end 
event_3BF_command_E65E:
    event_end 
