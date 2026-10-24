; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3E73
.include "src/rom/event_command_macros.inc"
event_4E5_command_3E73:
    event_call 1051
event_4E5_command_3E75:
    event_restore_hero 132
event_4E5_command_3E77:
    event_end 
