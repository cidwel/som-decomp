; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3B1E
.include "src/rom/event_command_macros.inc"
event_127_command_3B1E:
    event_actor_animation_loop 0, 164
