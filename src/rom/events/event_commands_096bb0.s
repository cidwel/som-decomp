; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6BB0
.include "src/rom/event_command_macros.inc"
event_1B7_command_6BB0:
    event_actor_effect_0f 
