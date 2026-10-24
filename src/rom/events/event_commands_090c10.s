; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0C10
.include "src/rom/event_command_macros.inc"
event_027_command_0C10:
    event_call 1051
event_027_command_0C12:
    event_restore_hero 132
event_027_command_0C14:
    event_end 
event_028_command_0C15:
    event_jump 1248
event_028_command_0C17:
    event_end 
