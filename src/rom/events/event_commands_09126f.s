; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $126F
.include "src/rom/event_command_macros.inc"
event_065_command_126F:
    event_jump 785
event_065_command_1271:
    event_jump 769
event_065_command_1273:
    event_jump 787
event_065_command_1275:
    event_end 
event_066_command_1276:
    event_end 
event_067_command_1277:
    event_end 
event_068_command_1278:
    event_end 
event_069_command_1279:
    event_end 
event_06A_command_127A:
    event_end 
event_06B_command_127B:
    event_end 
event_06C_command_127C:
    event_end 
event_06D_command_127D:
    event_end 
event_06E_command_127E:
    event_end 
event_06F_command_127F:
    event_end 
event_070_command_1280:
    event_jump 1249
event_070_command_1282:
    event_end 
event_071_command_1283:
    event_end 
event_072_command_1284:
    event_end 
event_073_command_1285:
    event_end 
event_074_command_1286:
    event_end 
event_075_command_1287:
    event_end 
event_076_command_1288:
    event_end 
event_077_command_1289:
    event_end 
event_078_command_128A:
    event_end 
event_079_command_128B:
    event_end 
event_07A_command_128C:
    event_end 
event_07B_command_128D:
    event_end 
event_07C_command_128E:
    event_end 
event_07D_command_128F:
    event_end 
event_07E_command_1290:
    event_end 
event_07F_command_1291:
    event_end 
event_080_command_1292:
    event_end 
event_081_command_1293:
    event_freeze 
event_081_command_1294:
    event_gather 
event_081_command_1295:
    event_call 1937
event_081_command_1297:
    event_call 1932
event_081_command_1299:
    event_redraw_pieces 
event_081_command_129A:
    event_increment_flag 1
event_081_command_129C:
    event_actor_walk 1, 0, 8
event_081_command_129F:
    event_wait_idle 
event_081_command_12A0:
    event_actor_walk 1, 0, 8
event_081_command_12A3:
    event_actor_walk 2, 0, 8
event_081_command_12A6:
    event_wait_idle 
event_081_command_12A7:
    event_actor_walk 1, 0, 56
event_081_command_12AA:
    event_actor_walk 2, 0, 56
event_081_command_12AD:
    event_actor_walk 3, 0, 56
event_081_command_12B0:
    event_wait_idle 
event_081_command_12B1:
    event_actor_walk 1, 0, 24
event_081_command_12B4:
    event_actor_walk 2, 0, 32
event_081_command_12B7:
    event_actor_walk 3, 0, 40
event_081_command_12BA:
    event_wait_idle 
event_081_command_12BB:
    event_call 1152
event_081_command_12BD:
    event_decrement_flag 1
