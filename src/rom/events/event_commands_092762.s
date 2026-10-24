; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2762
.include "src/rom/event_command_macros.inc"
event_103_command_2762:
    event_wait 32
event_103_command_2764:
    event_decrement_flag 10
event_103_command_2766:
    event_refresh_objects 
event_103_command_2767:
    event_screen 7
event_103_command_2769:
    event_wait 4
