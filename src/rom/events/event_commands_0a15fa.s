; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $15FA
.include "src/rom/event_command_macros.inc"
event_440_command_15FA:
    event_jump 1535
event_440_command_15FC:
    event_end 
event_441_command_15FD:
    event_end 
event_442_command_15FE:
    event_end 
event_443_command_15FF:
    event_end 
event_444_command_1600:
    event_end 
event_445_command_1601:
    event_end 
event_446_command_1602:
    event_end 
event_447_command_1603:
    event_end 
event_448_command_1604:
    event_end 
event_449_command_1605:
    event_end 
event_44A_command_1606:
    event_end 
event_44B_command_1607:
    event_end 
event_44C_command_1608:
    event_end 
event_44D_command_1609:
    event_end 
event_44E_command_160A:
    event_end 
event_44F_command_160B:
    event_end 
event_450_command_160C:
    event_call 1939
event_450_command_160E:
    event_change_map 125
event_450_command_1610:
    event_jump 1797
event_450_command_1612:
    event_end 
event_451_command_1613:
    event_call 1939
event_451_command_1615:
    event_change_map 168
event_451_command_1617:
    event_end 
event_452_command_1618:
    event_call 1939
event_452_command_161A:
    event_change_map 169
event_452_command_161C:
    event_end 
event_453_command_161D:
    event_call 1939
event_453_command_161F:
    event_change_map 170
event_453_command_1621:
    event_end 
event_454_command_1622:
    event_call 1939
event_454_command_1624:
    event_change_map 171
event_454_command_1626:
    event_end 
event_455_command_1627:
    event_call 1939
event_455_command_1629:
    event_change_map 256
event_455_command_162B:
    event_end 
event_456_command_162C:
    event_call 1939
event_456_command_162E:
    event_change_map 172
event_456_command_1630:
    event_end 
event_457_command_1631:
    event_call 1939
event_457_command_1633:
    event_change_map 173
event_457_command_1635:
    event_end 
event_458_command_1636:
    event_call 1940
event_458_command_1638:
    event_change_map 167
event_458_command_163A:
    event_jump 1559
event_458_command_163C:
    event_end 
event_459_command_163D:
    event_call 1939
event_459_command_163F:
    event_change_map 180
event_459_command_1641:
    event_jump 1558
event_459_command_1643:
    event_end 
event_45A_command_1644:
    event_call 1939
event_45A_command_1646:
    event_change_map 257
event_45A_command_1648:
    event_jump 1558
event_45A_command_164A:
    event_end 
event_45B_command_164B:
    event_call 1939
event_45B_command_164D:
    event_change_map 29
event_45B_command_164F:
    event_jump 1558
event_45B_command_1651:
    event_end 
event_45C_command_1652:
    event_end 
event_45D_command_1653:
    event_end 
event_45E_command_1654:
    event_end 
event_45F_command_1655:
    event_end 
event_460_command_1656:
    event_change_map 773
event_460_command_1658:
    event_end 
event_461_command_1659:
    event_end 
event_462_command_165A:
    event_end 
event_463_command_165B:
    event_end 
event_464_command_165C:
    event_end 
event_465_command_165D:
    event_end 
event_466_command_165E:
    event_end 
event_467_command_165F:
    event_end 
event_468_command_1660:
    event_end 
event_469_command_1661:
    event_end 
event_46A_command_1662:
    event_end 
event_46B_command_1663:
    event_end 
event_46C_command_1664:
    event_end 
event_46D_command_1665:
    event_end 
event_46E_command_1666:
    event_end 
event_46F_command_1667:
    event_end 
event_470_command_1668:
    event_end 
event_471_command_1669:
    event_end 
event_472_command_166A:
    event_end 
event_473_command_166B:
    event_end 
event_474_command_166C:
    event_end 
event_475_command_166D:
    event_end 
event_476_command_166E:
    event_end 
event_477_command_166F:
    event_end 
event_478_command_1670:
    event_end 
event_479_command_1671:
    event_end 
event_47A_command_1672:
    event_end 
event_47B_command_1673:
    event_end 
event_47C_command_1674:
    event_freeze 
event_47C_command_1675:
    event_gather 
event_47C_command_1676:
    event_screen 8
event_47C_command_1678:
    event_actor_walk 1, 1, 0
event_47C_command_167B:
    event_actor_walk 2, 3, 8
event_47C_command_167E:
    event_actor_walk 3, 2, 8
event_47C_command_1681:
    event_wait_idle 
event_47C_command_1682:
    event_actor_walk 1, 1, 0
event_47C_command_1685:
    event_actor_walk 2, 1, 0
event_47C_command_1688:
    event_actor_walk 3, 1, 0
event_47C_command_168B:
    event_wait_idle 
event_47C_command_168C:
    event_return 
event_47C_command_168D:
    event_end 
event_47D_command_168E:
    event_freeze 
event_47D_command_168F:
    event_gather 
event_47D_command_1690:
    event_screen 8
event_47D_command_1692:
    event_actor_walk 2, 0, 0
event_47D_command_1695:
    event_actor_walk 1, 3, 8
event_47D_command_1698:
    event_actor_walk 3, 2, 8
event_47D_command_169B:
    event_wait_idle 
event_47D_command_169C:
    event_actor_walk 2, 0, 0
event_47D_command_169F:
    event_actor_walk 1, 0, 0
event_47D_command_16A2:
    event_actor_walk 3, 0, 0
event_47D_command_16A5:
    event_wait_idle 
event_47D_command_16A6:
    event_return 
event_47D_command_16A7:
    event_end 
event_47E_command_16A8:
    event_freeze 
event_47E_command_16A9:
    event_gather 
event_47E_command_16AA:
    event_screen 8
event_47E_command_16AC:
    event_actor_walk 3, 0, 0
event_47E_command_16AF:
    event_actor_walk 1, 3, 8
event_47E_command_16B2:
    event_actor_walk 2, 2, 8
event_47E_command_16B5:
    event_wait_idle 
event_47E_command_16B6:
    event_actor_walk 3, 0, 0
event_47E_command_16B9:
    event_actor_walk 1, 0, 0
event_47E_command_16BC:
    event_actor_walk 2, 0, 0
event_47E_command_16BF:
    event_wait_idle 
event_47E_command_16C0:
    event_return 
event_47E_command_16C1:
    event_end 
event_47F_command_16C2:
    event_freeze 
event_47F_command_16C3:
    event_gather 
event_47F_command_16C4:
    event_screen 8
event_47F_command_16C6:
    event_actor_walk 1, 0, 0
event_47F_command_16C9:
    event_actor_walk 2, 3, 8
event_47F_command_16CC:
    event_actor_walk 3, 2, 8
event_47F_command_16CF:
    event_wait_idle 
event_47F_command_16D0:
    event_actor_walk 1, 0, 0
event_47F_command_16D3:
    event_actor_walk 2, 0, 0
event_47F_command_16D6:
    event_actor_walk 3, 0, 0
event_47F_command_16D9:
    event_wait_idle 
event_47F_command_16DA:
    event_return 
event_47F_command_16DB:
    event_end 
event_480_command_16DC:
    event_test_actor 0
event_480_command_16DE:
    event_jump 1151
event_480_command_16E0:
    event_test_actor 1
event_480_command_16E2:
    event_jump 1149
event_480_command_16E4:
    event_test_actor 2
event_480_command_16E6:
    event_jump 1150
event_480_command_16E8:
    event_end 
event_481_command_16E9:
    event_end 
