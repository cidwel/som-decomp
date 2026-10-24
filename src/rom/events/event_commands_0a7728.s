; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7728
.include "src/rom/event_command_macros.inc"
event_59B_command_7728:
    event_change_map 795
event_59B_command_772A:
    event_end 
event_59C_command_772B:
    event_end 
event_59D_command_772C:
    event_actor_walk 0, 0, 0
event_59D_command_772F:
    event_wait_idle 
