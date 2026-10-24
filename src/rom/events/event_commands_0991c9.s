; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $91C9
.include "src/rom/event_command_macros.inc"
event_208_command_91C9:
    event_end 
event_209_command_91CA:
    event_set_flag 46, 2
event_209_command_91CD:
    event_return 
event_209_command_91CE:
    event_end 
