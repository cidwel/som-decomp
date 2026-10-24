; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2790
.include "src/rom/event_command_macros.inc"
event_103_command_2790:
    event_set_actor_field 0, 144, 0
event_103_command_2794:
    event_screen_word 6, 17407
event_103_command_2798:
    event_wait 8
