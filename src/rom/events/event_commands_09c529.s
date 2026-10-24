; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C529
.include "src/rom/event_command_macros.inc"
event_2DE_command_C529:
    event_call 1051
event_2DE_command_C52B:
    event_restore_hero 132
event_2DE_command_C52D:
    event_jump 80
event_2DE_command_C52F:
    event_end 
