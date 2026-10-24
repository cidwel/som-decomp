; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3745
.include "src/rom/event_command_macros.inc"
event_4E3_command_3745:
    event_call 1854
event_4E3_command_3747:
    event_wait 32
event_4E3_command_3749:
    event_call 1836
event_4E3_command_374B:
    event_increment_flag 248
