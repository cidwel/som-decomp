; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2683
.include "src/rom/event_command_macros.inc"
event_103_command_2683:
    event_call 1864
event_103_command_2685:
    event_screen 8
event_103_command_2687:
    event_set_actor_field 0, 144, 1
event_103_command_268B:
    event_actor_animation 0, 173
