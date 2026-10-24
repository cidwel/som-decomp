; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $24FC
.include "src/rom/event_command_macros.inc"
event_4B9_command_24FC:
    event_jump 1535
event_4B9_command_24FE:
    event_end 
event_4BA_command_24FF:
    event_end 
event_4BB_command_2500:
    event_end 
event_4BC_command_2501:
    event_end 
event_4BD_command_2502:
    event_call 1932
event_4BD_command_2504:
    event_increment_flag 73
event_4BD_command_2506:
    event_redraw_pieces 
event_4BD_command_2507:
    event_end 
event_4BE_command_2508:
    event_call 1932
event_4BE_command_250A:
    event_increment_flag 72
event_4BE_command_250C:
    event_redraw_pieces 
event_4BE_command_250D:
    event_end 
event_4BF_command_250E:
    event_call 1932
event_4BF_command_2510:
    event_increment_flag 72
event_4BF_command_2512:
    event_increment_flag 73
event_4BF_command_2514:
    event_redraw_pieces 
event_4BF_command_2515:
    event_end 
event_4C0_command_2516:
    event_test_flag_range 72, 0, 0
event_4C0_command_2519:
    event_jump 1215
event_4C0_command_251B:
    event_end 
event_4C1_command_251C:
    event_test_flag_range 72, 0, 1
event_4C1_command_251F:
    event_jump 1214
event_4C1_command_2521:
    event_end 
event_4C2_command_2522:
    event_test_flag_range 72, 0, 2
event_4C2_command_2525:
    event_jump 1214
event_4C2_command_2527:
    event_end 
event_4C3_command_2528:
    event_test_flag_range 73, 0, 1
event_4C3_command_252B:
    event_jump 1213
event_4C3_command_252D:
    event_end 
event_4C4_command_252E:
    event_test_flag_range 73, 0, 2
event_4C4_command_2531:
    event_jump 1222
event_4C4_command_2533:
    event_end 
event_4C5_command_2534:
    event_freeze 
event_4C5_command_2535:
    event_gather 
event_4C5_command_2536:
    event_call 1932
event_4C5_command_2538:
    event_increment_flag 76
event_4C5_command_253A:
    event_redraw_pieces 
event_4C5_command_253B:
    event_actor_walk 1, 0, 16
event_4C5_command_253E:
    event_actor_walk 3, 0, 8
event_4C5_command_2541:
    event_wait_idle 
event_4C5_command_2542:
    event_actor_walk 1, 0, 16
event_4C5_command_2545:
    event_actor_walk 2, 0, 16
event_4C5_command_2548:
    event_actor_walk 3, 0, 16
event_4C5_command_254B:
    event_wait_idle 
event_4C5_command_254C:
    event_actor_walk 1, 0, 48
event_4C5_command_254F:
    event_actor_walk 2, 0, 63
event_4C5_command_2552:
    event_actor_walk 3, 0, 56
event_4C5_command_2555:
    event_wait_idle 
event_4C5_command_2556:
    event_gather 
event_4C5_command_2557:
    event_call 1932
event_4C5_command_2559:
    event_decrement_flag 76
event_4C5_command_255B:
    event_redraw_pieces 
event_4C5_command_255C:
    event_set_flag 255, 0
event_4C5_command_255F:
    event_test_flag_range 68, 1, 1
event_4C5_command_2562:
    event_jump 1796
event_4C5_command_2564:
    event_end 
event_4C6_command_2565:
    event_increment_flag 68
event_4C6_command_2567:
    event_call 1932
event_4C6_command_2569:
    event_increment_flag 73
event_4C6_command_256B:
    event_redraw_pieces 
event_4C6_command_256C:
    event_end 
event_4C7_command_256D:
    event_end 
event_4C8_command_256E:
    event_test_flag_range 71, 3, 15
event_4C8_command_2571:
    event_jump 0
event_4C8_command_2573:
    event_call 2013
event_4C8_command_2575:
    event_actor_walk 0, 0, 8
event_4C8_command_2578:
    event_wait_idle 
event_4C8_command_2579:
    event_call 1152
