; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $26B1
.include "src/rom/event_command_macros.inc"
event_103_command_26B1:
    event_set_actor_field 0, 144, 1
event_103_command_26B5:
    event_screen_word 6, 17407
