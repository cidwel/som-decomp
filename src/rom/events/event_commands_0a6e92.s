; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E92
.include "src/rom/event_command_macros.inc"
event_581_command_6E92:
    event_actor_animation 3, 168
event_581_command_6E95:
    event_jump 1535
event_581_command_6E97:
    event_end 
