; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1713
.include "src/rom/event_command_macros.inc"
event_485_command_1713:
    event_freeze 
event_485_command_1714:
    event_gather 
event_485_command_1715:
    event_set_flag 1, 1
event_485_command_1718:
    event_test_actor 1
event_485_command_171A:
    event_jump 1156
event_485_command_171C:
    event_test_actor 2
event_485_command_171E:
    event_jump 1155
event_485_command_1720:
    event_actor_walk 1, 3, 24
event_485_command_1723:
    event_wait_idle 
event_485_command_1724:
    event_actor_walk 1, 3, 24
event_485_command_1727:
    event_actor_walk 3, 3, 24
event_485_command_172A:
    event_wait_idle 
event_485_command_172B:
    event_jump 1158
event_485_command_172D:
    event_end 
event_486_command_172E:
    event_call 1864
event_486_command_1730:
    event_actor_walk 1, 3, 48
event_486_command_1733:
    event_actor_walk 3, 3, 48
event_486_command_1736:
    event_actor_walk 2, 3, 48
event_486_command_1739:
    event_wait_idle 
event_486_command_173A:
    event_actor_walk 1, 0, 21
event_486_command_173D:
    event_actor_walk 3, 0, 21
event_486_command_1740:
    event_actor_walk 2, 0, 21
event_486_command_1743:
    event_wait_idle 
event_486_command_1744:
    event_test_flag_range 112, 0, 0
event_486_command_1747:
    event_call 824
event_486_command_1749:
    event_test_flag_range 113, 0, 0
event_486_command_174C:
    event_call 825
event_486_command_174E:
    event_test_flag_range 114, 0, 0
event_486_command_1751:
    event_call 826
event_486_command_1753:
    event_wait_idle 
event_486_command_1754:
    event_screen_word 5, 33791
event_486_command_1758:
    event_set_flag 1, 3
event_486_command_175B:
    event_test_flag_range 112, 0, 0
event_486_command_175E:
    event_call 827
event_486_command_1760:
    event_test_flag_range 113, 0, 0
event_486_command_1763:
    event_call 828
event_486_command_1765:
    event_test_flag_range 114, 0, 0
event_486_command_1768:
    event_call 829
event_486_command_176A:
    event_call 1853
event_486_command_176C:
    event_audio_request 1, 7, 72, 47
event_486_command_1771:
    event_wait_idle 
event_486_command_1772:
    event_call 1051
event_486_command_1774:
    event_restore_hero 132
event_486_command_1776:
    event_screen 7
event_486_command_1778:
    event_test_flag_range 112, 0, 0
event_486_command_177B:
    event_call 830
event_486_command_177D:
    event_test_flag_range 113, 0, 0
event_486_command_1780:
    event_call 831
event_486_command_1782:
    event_test_flag_range 114, 0, 0
event_486_command_1785:
    event_call 819
event_486_command_1787:
    event_wait_idle 
event_486_command_1788:
    event_set_flag 1, 0
event_486_command_178B:
    event_unfreeze 
event_486_command_178C:
    event_call 1810
event_486_command_178E:
    event_jump 80
event_486_command_1790:
    event_end 
event_487_command_1791:
    event_end 
event_488_command_1792:
    event_end 
event_489_command_1793:
    event_end 
event_48A_command_1794:
    event_end 
event_48B_command_1795:
    event_end 
event_48C_command_1796:
    event_end 
event_48D_command_1797:
    event_end 
event_48E_command_1798:
    event_end 
event_48F_command_1799:
    event_end 
event_490_command_179A:
    event_end 
event_491_command_179B:
    event_end 
event_492_command_179C:
    event_end 
event_493_command_179D:
    event_end 
event_494_command_179E:
    event_end 
event_495_command_179F:
    event_end 
event_496_command_17A0:
    event_end 
event_497_command_17A1:
    event_end 
event_498_command_17A2:
    event_end 
event_499_command_17A3:
    event_end 
event_49A_command_17A4:
    event_end 
event_49B_command_17A5:
    event_end 
event_49C_command_17A6:
    event_end 
event_49D_command_17A7:
    event_end 
event_49E_command_17A8:
    event_end 
event_49F_command_17A9:
    event_call 2009
event_49F_command_17AB:
    event_end 
event_4A0_command_17AC:
    event_test_flag_range 65, 0, 0
event_4A0_command_17AF:
    event_jump 1183
event_4A0_command_17B1:
    event_test_flag_range 68, 3, 15
event_4A0_command_17B4:
    event_jump 0
event_4A0_command_17B6:
    event_call 1864
