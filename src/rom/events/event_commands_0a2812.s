; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2812
.include "src/rom/event_command_macros.inc"
event_4D0_command_2812:
    event_increment_flag 92
event_4D0_command_2814:
    event_jump 1557
event_4D0_command_2816:
    event_end 
event_4D1_command_2817:
    event_end 
event_4D2_command_2818:
    event_end 
event_4D3_command_2819:
    event_end 
