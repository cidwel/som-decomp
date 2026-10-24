; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7259
.include "src/rom/event_command_macros.inc"
event_587_command_7259:
    event_call 2003
event_587_command_725B:
    event_end 
event_588_command_725C:
    event_test_flag_range 144, 1, 1
event_588_command_725F:
    event_jump 1448
event_588_command_7261:
    event_test_flag_range 69, 1, 15
event_588_command_7264:
    event_jump 1427
event_588_command_7266:
    event_freeze 
event_588_command_7267:
    event_gather 
event_588_command_7268:
    event_screen 8
event_588_command_726A:
    event_screen 0
event_588_command_726C:
    event_wait 1
event_588_command_726E:
    event_screen 1
event_588_command_7270:
    event_screen_word 5, 30313
event_588_command_7274:
    event_call 1424
event_588_command_7276:
    event_set_flag 144, 1
event_588_command_7279:
    event_refresh_objects 
event_588_command_727A:
    event_end 
event_589_command_727B:
    event_test_flag_range 147, 1, 1
event_589_command_727E:
    event_jump 1449
event_589_command_7280:
    event_test_flag_range 69, 1, 15
event_589_command_7283:
    event_jump 1427
event_589_command_7285:
    event_freeze 
event_589_command_7286:
    event_gather 
event_589_command_7287:
    event_screen 8
event_589_command_7289:
    event_screen 0
event_589_command_728B:
    event_wait 1
event_589_command_728D:
    event_screen 1
event_589_command_728F:
    event_screen_word 5, 31
event_589_command_7293:
    event_call 1424
event_589_command_7295:
    event_call 1428
event_589_command_7297:
    event_set_flag 147, 1
event_589_command_729A:
    event_refresh_objects 
event_589_command_729B:
    event_end 
event_58A_command_729C:
    event_test_flag_range 146, 1, 1
event_58A_command_729F:
    event_jump 1450
event_58A_command_72A1:
    event_test_flag_range 69, 1, 15
event_58A_command_72A4:
    event_jump 1427
event_58A_command_72A6:
    event_freeze 
event_58A_command_72A7:
    event_gather 
event_58A_command_72A8:
    event_screen 8
event_58A_command_72AA:
    event_screen 0
event_58A_command_72AC:
    event_wait 1
event_58A_command_72AE:
    event_screen 1
event_58A_command_72B0:
    event_screen_word 5, 30418
event_58A_command_72B4:
    event_call 1424
event_58A_command_72B6:
    event_call 1428
event_58A_command_72B8:
    event_set_flag 146, 1
event_58A_command_72BB:
    event_refresh_objects 
event_58A_command_72BC:
    event_end 
event_58B_command_72BD:
    event_test_flag_range 24, 7, 7
event_58B_command_72C0:
    event_jump 1426
event_58B_command_72C2:
    event_test_flag_range 145, 1, 1
event_58B_command_72C5:
    event_jump 1451
event_58B_command_72C7:
    event_test_flag_range 69, 1, 15
event_58B_command_72CA:
    event_jump 1427
event_58B_command_72CC:
    event_freeze 
event_58B_command_72CD:
    event_gather 
event_58B_command_72CE:
    event_screen 8
event_58B_command_72D0:
    event_screen 0
event_58B_command_72D2:
    event_wait 1
event_58B_command_72D4:
    event_screen 1
event_58B_command_72D6:
    event_screen_word 5, 4535
event_58B_command_72DA:
    event_call 1424
event_58B_command_72DC:
    event_set_flag 145, 1
event_58B_command_72DF:
    event_refresh_objects 
event_58B_command_72E0:
    event_end 
event_58C_command_72E1:
    event_test_flag_range 148, 1, 1
event_58C_command_72E4:
    event_jump 1452
event_58C_command_72E6:
    event_test_flag_range 69, 1, 15
event_58C_command_72E9:
    event_jump 1427
event_58C_command_72EB:
    event_freeze 
event_58C_command_72EC:
    event_gather 
event_58C_command_72ED:
    event_screen 8
event_58C_command_72EF:
    event_screen 0
event_58C_command_72F1:
    event_wait 1
event_58C_command_72F3:
    event_screen 1
event_58C_command_72F5:
    event_screen_word 5, 32767
event_58C_command_72F9:
    event_call 1424
event_58C_command_72FB:
    event_call 1428
event_58C_command_72FD:
    event_set_flag 148, 1
event_58C_command_7300:
    event_refresh_objects 
event_58C_command_7301:
    event_end 
event_58D_command_7302:
    event_test_flag_range 149, 1, 1
event_58D_command_7305:
    event_jump 1453
event_58D_command_7307:
    event_test_flag_range 69, 1, 15
event_58D_command_730A:
    event_jump 1427
event_58D_command_730C:
    event_freeze 
event_58D_command_730D:
    event_gather 
event_58D_command_730E:
    event_screen 8
event_58D_command_7310:
    event_screen 0
event_58D_command_7312:
    event_wait 1
event_58D_command_7314:
    event_screen 1
event_58D_command_7316:
    event_screen_word 5, 6342
event_58D_command_731A:
    event_call 1424
event_58D_command_731C:
    event_call 1428
event_58D_command_731E:
    event_set_flag 149, 1
event_58D_command_7321:
    event_refresh_objects 
event_58D_command_7322:
    event_end 
event_58E_command_7323:
    event_test_flag_range 150, 1, 1
event_58E_command_7326:
    event_jump 1454
event_58E_command_7328:
    event_test_flag_range 69, 1, 15
event_58E_command_732B:
    event_jump 1427
event_58E_command_732D:
    event_freeze 
event_58E_command_732E:
    event_gather 
event_58E_command_732F:
    event_screen 8
event_58E_command_7331:
    event_screen 0
event_58E_command_7333:
    event_wait 1
event_58E_command_7335:
    event_screen 1
event_58E_command_7337:
    event_screen_word 5, 1023
event_58E_command_733B:
    event_call 1424
event_58E_command_733D:
    event_call 1428
event_58E_command_733F:
    event_set_flag 150, 1
event_58E_command_7342:
    event_refresh_objects 
event_58E_command_7343:
    event_end 
event_58F_command_7344:
    event_test_flag_range 151, 1, 1
event_58F_command_7347:
    event_jump 1455
event_58F_command_7349:
    event_test_flag_range 69, 1, 15
event_58F_command_734C:
    event_jump 1427
event_58F_command_734E:
    event_freeze 
event_58F_command_734F:
    event_gather 
event_58F_command_7350:
    event_screen 8
event_58F_command_7352:
    event_screen 0
event_58F_command_7354:
    event_wait 1
event_58F_command_7356:
    event_screen 1
event_58F_command_7358:
    event_screen_word 5, 992
event_58F_command_735C:
    event_call 1424
event_58F_command_735E:
    event_call 1428
event_58F_command_7360:
    event_set_flag 151, 1
event_58F_command_7363:
    event_refresh_objects 
event_58F_command_7364:
    event_end 
event_590_command_7365:
    event_actor_walk 128, 0, 0
event_590_command_7368:
    event_wait_idle 
event_590_command_7369:
    event_actor_animation_loop 128, 129
event_590_command_736C:
    event_wait_idle 
event_590_command_736D:
    event_wait 8
event_590_command_736F:
    event_actor_walk 128, 2, 0
event_590_command_7372:
    event_wait_idle 
event_590_command_7373:
    event_audio_request 2, 23, 15, 136
event_590_command_7378:
    event_wait 16
event_590_command_737A:
    event_audio_request 2, 23, 15, 136
event_590_command_737F:
    event_wait 16
event_590_command_7381:
    event_audio_request 2, 23, 15, 136
event_590_command_7386:
    event_actor_walk 128, 1, 0
event_590_command_7389:
    event_wait_idle 
event_590_command_738A:
    event_actor_animation_loop 128, 129
event_590_command_738D:
    event_wait_idle 
event_590_command_738E:
    event_wait 8
event_590_command_7390:
    event_actor_animation_loop 128, 128
event_590_command_7393:
    event_wait_idle 
event_590_command_7394:
    event_screen 7
