; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BCB8
.include "src/rom/event_command_macros.inc"
event_2C1_command_BCB8:
    event_actor_walk 4, 0, 0
event_2C1_command_BCBB:
    event_wait_idle 
event_2C1_command_BCBC:
    event_wait 128
event_2C1_command_BCBE:
    event_change_map 632
event_2C1_command_BCC0:
    event_call 1928
