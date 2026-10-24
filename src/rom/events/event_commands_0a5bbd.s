; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5BBD
.include "src/rom/event_command_macros.inc"
event_511_command_5BBD:
    event_actor_walk 0, 2, 16
event_511_command_5BC0:
    event_wait_idle 
event_511_command_5BC1:
    event_actor_walk 0, 3, 0
event_511_command_5BC4:
    event_wait_idle 
event_511_command_5BC5:
    event_gather 
event_511_command_5BC6:
    event_actor_walk 4, 1, 16
event_511_command_5BC9:
    event_actor_walk 5, 1, 0
event_511_command_5BCC:
    event_actor_walk 6, 3, 32
event_511_command_5BCF:
    event_wait_idle 
event_511_command_5BD0:
    event_actor_walk 4, 1, 32
event_511_command_5BD3:
    event_actor_walk 5, 2, 32
event_511_command_5BD6:
    event_actor_walk 6, 1, 32
event_511_command_5BD9:
    event_wait_idle 
event_511_command_5BDA:
    event_actor_walk 4, 1, 63
event_511_command_5BDD:
    event_actor_walk 5, 1, 63
event_511_command_5BE0:
    event_actor_walk 6, 1, 63
event_511_command_5BE3:
    event_wait_idle 
event_511_command_5BE4:
    event_set_flag 50, 3
event_511_command_5BE7:
    event_refresh_objects 
event_511_command_5BE8:
    event_set_flag 52, 0
event_511_command_5BEB:
    event_end 
event_512_command_5BEC:
    event_end 
event_513_command_5BED:
    event_end 
event_514_command_5BEE:
    event_end 
event_515_command_5BEF:
    event_end 
event_516_command_5BF0:
    event_end 
event_517_command_5BF1:
    event_end 
event_518_command_5BF2:
    event_end 
event_519_command_5BF3:
    event_end 
event_51A_command_5BF4:
    event_end 
event_51B_command_5BF5:
    event_call 1932
event_51B_command_5BF7:
    event_increment_flag 53
event_51B_command_5BF9:
    event_redraw_pieces 
event_51B_command_5BFA:
    event_end 
event_51C_command_5BFB:
    event_end 
event_51D_command_5BFC:
    event_test_flag_range 52, 1, 15
event_51D_command_5BFF:
    event_jump 0
