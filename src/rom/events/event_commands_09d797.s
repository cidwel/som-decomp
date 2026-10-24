; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D797
.include "src/rom/event_command_macros.inc"
event_375_command_D797:
    event_actor_effect_0f 
