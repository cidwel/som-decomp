; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7038
.include "src/rom/event_command_macros.inc"
event_584_command_7038:
    event_set_flag 174, 2
event_584_command_703B:
    event_refresh_objects 
