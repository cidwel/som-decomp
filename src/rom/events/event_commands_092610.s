; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2610
.include "src/rom/event_command_macros.inc"
event_102_command_2610:
    event_jump 1535
event_102_command_2612:
    event_end 
event_103_command_2613:
    event_screen_word 6, 17407
