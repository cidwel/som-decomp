; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7121
.include "src/rom/event_command_macros.inc"
event_586_command_7121:
    event_set_flag 173, 2
event_586_command_7124:
    event_refresh_objects 
