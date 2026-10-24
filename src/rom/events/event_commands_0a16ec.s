; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $16EC
.include "src/rom/event_command_macros.inc"
event_482_command_16EC:
    event_call 1152
event_482_command_16EE:
    event_actor_effect_0f 
