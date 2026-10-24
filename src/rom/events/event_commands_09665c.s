; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $665C
.include "src/rom/event_command_macros.inc"
event_1B2_command_665C:
    event_audio_request 2, 137, 15, 136
event_1B2_command_6661:
    event_actor_walk 128, 3, 0
event_1B2_command_6664:
    event_wait_idle 
event_1B2_command_6665:
    event_wait 16
event_1B2_command_6667:
    event_actor_walk 128, 2, 0
event_1B2_command_666A:
    event_wait_idle 
event_1B2_command_666B:
    event_wait 16
event_1B2_command_666D:
    event_actor_walk 128, 3, 0
event_1B2_command_6670:
    event_wait_idle 
event_1B2_command_6671:
    event_wait 16
event_1B2_command_6673:
    event_actor_walk 128, 2, 0
event_1B2_command_6676:
    event_wait_idle 
event_1B2_command_6677:
    event_wait 16
event_1B2_command_6679:
    event_hero_command 138
event_1B2_command_667B:
    event_party_command 8
event_1B2_command_667D:
    event_restore_hero 68
event_1B2_command_667F:
    event_set_flag 177, 1
event_1B2_command_6682:
    event_actor_walk 128, 1, 0
event_1B2_command_6685:
    event_wait_idle 
