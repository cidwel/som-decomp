; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E44C
.include "src/rom/event_command_macros.inc"
event_3B1_command_E44C:
    event_jump 1535
event_3B1_command_E44E:
    event_end 
