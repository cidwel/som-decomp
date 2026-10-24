; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $283C
.include "src/rom/event_command_macros.inc"
event_4D4_command_283C:
    event_return 
event_4D4_command_283D:
    event_end 
event_4D5_command_283E:
    event_end 
event_4D6_command_283F:
    event_end 
event_4D7_command_2840:
    event_end 
event_4D8_command_2841:
    event_increment_flag 93
event_4D8_command_2843:
    event_increment_flag 248
