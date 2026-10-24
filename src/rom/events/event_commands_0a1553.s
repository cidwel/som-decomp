; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1553
.include "src/rom/event_command_macros.inc"
event_42D_command_1553:
    event_increment_flag 78
event_42D_command_1555:
    event_set_actor_field 2, 205, 56
event_42D_command_1559:
    event_set_actor_field 3, 205, 7
event_42D_command_155D:
    event_end 
event_42E_command_155E:
    event_end 
event_42F_command_155F:
    event_increment_flag 78
event_42F_command_1561:
    event_increment_flag 255
event_42F_command_1563:
    event_jump 1023
event_42F_command_1565:
    event_end 
event_430_command_1566:
    event_test_flag_range 79, 1, 15
event_430_command_1569:
    event_jump 0
event_430_command_156B:
    event_call 1937
event_430_command_156D:
    event_call 1079
event_430_command_156F:
    event_call 1079
event_430_command_1571:
    event_end 
event_431_command_1572:
    event_test_flag_range 79, 3, 15
event_431_command_1575:
    event_jump 0
event_431_command_1577:
    event_call 1937
event_431_command_1579:
    event_call 1079
event_431_command_157B:
    event_call 1079
event_431_command_157D:
    event_end 
event_432_command_157E:
    event_test_flag_range 79, 5, 15
event_432_command_1581:
    event_jump 0
event_432_command_1583:
    event_call 1937
event_432_command_1585:
    event_call 1079
event_432_command_1587:
    event_end 
event_433_command_1588:
    event_test_flag_range 79, 6, 15
event_433_command_158B:
    event_jump 0
event_433_command_158D:
    event_call 1937
event_433_command_158F:
    event_call 1079
event_433_command_1591:
    event_end 
event_434_command_1592:
    event_test_flag_range 79, 7, 15
event_434_command_1595:
    event_jump 0
event_434_command_1597:
    event_call 1937
event_434_command_1599:
    event_call 1079
event_434_command_159B:
    event_end 
event_435_command_159C:
    event_test_flag_range 79, 8, 15
event_435_command_159F:
    event_jump 0
event_435_command_15A1:
    event_call 1937
event_435_command_15A3:
    event_call 1079
event_435_command_15A5:
    event_call 1079
event_435_command_15A7:
    event_end 
event_436_command_15A8:
    event_test_flag_range 79, 10, 15
event_436_command_15AB:
    event_jump 0
event_436_command_15AD:
    event_call 1937
event_436_command_15AF:
    event_call 1079
event_436_command_15B1:
    event_call 1079
event_436_command_15B3:
    event_call 1079
event_436_command_15B5:
    event_call 1079
event_436_command_15B7:
    event_call 1079
event_436_command_15B9:
    event_end 
event_437_command_15BA:
    event_audio_request 2, 29, 15, 136
event_437_command_15BF:
    event_increment_flag 79
event_437_command_15C1:
    event_redraw_pieces 
event_437_command_15C2:
    event_return 
event_437_command_15C3:
    event_end 
event_438_command_15C4:
    event_end 
event_439_command_15C5:
    event_end 
event_43A_command_15C6:
    event_end 
event_43B_command_15C7:
    event_end 
event_43C_command_15C8:
    event_end 
event_43D_command_15C9:
    event_end 
event_43E_command_15CA:
    event_end 
event_43F_command_15CB:
    event_end 
