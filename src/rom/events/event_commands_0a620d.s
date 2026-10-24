; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $620D
.include "src/rom/event_command_macros.inc"
event_532_command_620D:
    event_hero_command 71
event_532_command_620F:
    event_audio_request 2, 35, 0, 136
event_532_command_6214:
    event_increment_flag 53
event_532_command_6216:
    event_set_flag 36, 15
event_532_command_6219:
    event_warp 100
event_532_command_621B:
    event_end 
event_533_command_621C:
    event_actor_walk 1, 0, 60
event_533_command_621F:
    event_actor_walk 2, 0, 60
event_533_command_6222:
    event_actor_walk 3, 0, 60
event_533_command_6225:
    event_wait_idle 
event_533_command_6226:
    event_return 
event_533_command_6227:
    event_end 
event_534_command_6228:
    event_end 
event_535_command_6229:
    event_end 
event_536_command_622A:
    event_end 
event_537_command_622B:
    event_end 
event_538_command_622C:
    event_end 
event_539_command_622D:
    event_end 
event_53A_command_622E:
    event_end 
event_53B_command_622F:
    event_end 
event_53C_command_6230:
    event_end 
event_53D_command_6231:
    event_end 
event_53E_command_6232:
    event_end 
event_53F_command_6233:
    event_end 
event_540_command_6234:
    event_jump 1843
event_540_command_6236:
    event_end 
event_541_command_6237:
    event_call 2009
event_541_command_6239:
    event_end 
event_542_command_623A:
    event_call 2002
event_542_command_623C:
    event_end 
event_543_command_623D:
    event_change_map 58
event_543_command_623F:
    event_set_flag 11, 15
event_543_command_6242:
    event_call 1988
event_543_command_6244:
    event_increment_flag 255
