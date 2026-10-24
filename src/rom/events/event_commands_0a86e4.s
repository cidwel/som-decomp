; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $86E4
.include "src/rom/event_command_macros.inc"
event_60C_command_86E4:
    event_return 
event_60C_command_86E5:
    event_end 
event_60D_command_86E6:
    event_end 
event_60E_command_86E7:
    event_end 
event_60F_command_86E8:
    event_call 1854
event_60F_command_86EA:
    event_end 
event_610_command_86EB:
    event_set_flag 253, 0
event_610_command_86EE:
    event_set_flag 254, 0
event_610_command_86F1:
    event_test_flag_range 9, 2, 15
event_610_command_86F4:
    event_jump 1800
event_610_command_86F6:
    event_test_flag_range 16, 0, 9
event_610_command_86F9:
    event_jump 1809
event_610_command_86FB:
    event_call 1844
event_610_command_86FD:
    event_end 
event_611_command_86FE:
    event_set_flag 253, 0
event_611_command_8701:
    event_set_flag 254, 1
event_611_command_8704:
    event_jump 1809
event_611_command_8706:
    event_end 
event_612_command_8707:
    event_jump 1821
event_612_command_8709:
    event_end 
event_613_command_870A:
    event_set_flag 253, 0
event_613_command_870D:
    event_set_flag 254, 3
event_613_command_8710:
    event_test_flag_range 18, 0, 8
event_613_command_8713:
    event_jump 1616
event_613_command_8715:
    event_jump 1809
event_613_command_8717:
    event_end 
event_614_command_8718:
    event_set_flag 253, 0
event_614_command_871B:
    event_set_flag 254, 4
event_614_command_871E:
    event_jump 1809
event_614_command_8720:
    event_end 
event_615_command_8721:
    event_set_flag 253, 0
event_615_command_8724:
    event_set_flag 254, 5
event_615_command_8727:
    event_jump 1823
event_615_command_8729:
    event_end 
event_616_command_872A:
    event_set_flag 253, 0
event_616_command_872D:
    event_set_flag 254, 6
event_616_command_8730:
    event_call 1998
event_616_command_8732:
    event_end 
event_617_command_8733:
    event_set_flag 253, 0
event_617_command_8736:
    event_set_flag 254, 7
event_617_command_8739:
    event_call 1998
event_617_command_873B:
    event_test_flag_range 217, 2, 2
event_617_command_873E:
    event_jump 502
event_617_command_8740:
    event_end 
event_618_command_8741:
    event_set_flag 253, 0
event_618_command_8744:
    event_set_flag 254, 8
event_618_command_8747:
    event_test_flag_range 23, 6, 15
event_618_command_874A:
    event_jump 1812
event_618_command_874C:
    event_call 1998
event_618_command_874E:
    event_end 
event_619_command_874F:
    event_set_flag 253, 0
event_619_command_8752:
    event_set_flag 254, 9
event_619_command_8755:
    event_set_flag 10, 0
event_619_command_8758:
    event_call 2011
event_619_command_875A:
    event_test_flag_range 32, 0, 0
event_619_command_875D:
    event_jump 601
event_619_command_875F:
    event_end 
event_61A_command_8760:
    event_set_flag 253, 0
event_61A_command_8763:
    event_set_flag 254, 10
event_61A_command_8766:
    event_test_flag_range 33, 0, 2
event_61A_command_8769:
    event_jump 592
event_61A_command_876B:
    event_call 1995
event_61A_command_876D:
    event_end 
event_61B_command_876E:
    event_set_flag 253, 0
event_61B_command_8771:
    event_set_flag 254, 11
event_61B_command_8774:
    event_test_flag_range 33, 13, 14
event_61B_command_8777:
    event_jump 1834
event_61B_command_8779:
    event_jump 1821
event_61B_command_877B:
    event_end 
event_61C_command_877C:
    event_set_flag 253, 0
event_61C_command_877F:
    event_set_flag 254, 12
event_61C_command_8782:
    event_jump 1814
event_61C_command_8784:
    event_end 
event_61D_command_8785:
    event_set_flag 253, 0
event_61D_command_8788:
    event_set_flag 254, 13
event_61D_command_878B:
    event_jump 1809
event_61D_command_878D:
    event_end 
event_61E_command_878E:
    event_set_flag 253, 0
event_61E_command_8791:
    event_set_flag 254, 14
event_61E_command_8794:
    event_call 1986
event_61E_command_8796:
    event_test_flag_range 40, 0, 0
event_61E_command_8799:
    event_jump 649
event_61E_command_879B:
    event_end 
event_61F_command_879C:
    event_set_flag 253, 0
event_61F_command_879F:
    event_set_flag 254, 15
event_61F_command_87A2:
    event_test_flag_range 41, 2, 15
event_61F_command_87A5:
    event_jump 1801
event_61F_command_87A7:
    event_jump 1807
event_61F_command_87A9:
    event_end 
event_620_command_87AA:
    event_set_flag 253, 1
event_620_command_87AD:
    event_set_flag 254, 0
event_620_command_87B0:
    event_set_flag 10, 0
event_620_command_87B3:
    event_call 1928
event_620_command_87B5:
    event_jump 1805
event_620_command_87B7:
    event_end 
event_621_command_87B8:
    event_set_flag 253, 1
event_621_command_87BB:
    event_set_flag 254, 1
event_621_command_87BE:
    event_test_flag_range 50, 0, 2
event_621_command_87C1:
    event_call 1608
event_621_command_87C3:
    event_jump 1805
event_621_command_87C5:
    event_end 
event_622_command_87C6:
    event_set_flag 253, 1
event_622_command_87C9:
    event_set_flag 254, 2
event_622_command_87CC:
    event_jump 1805
event_622_command_87CE:
    event_end 
event_623_command_87CF:
    event_set_flag 253, 1
event_623_command_87D2:
    event_set_flag 254, 3
event_623_command_87D5:
    event_jump 1821
event_623_command_87D7:
    event_end 
event_624_command_87D8:
    event_set_flag 253, 1
event_624_command_87DB:
    event_set_flag 254, 4
event_624_command_87DE:
    event_jump 1797
event_624_command_87E0:
    event_end 
event_625_command_87E1:
    event_set_flag 253, 1
event_625_command_87E4:
    event_set_flag 254, 5
event_625_command_87E7:
    event_set_flag 11, 2
event_625_command_87EA:
    event_jump 1798
event_625_command_87EC:
    event_end 
event_626_command_87ED:
    event_set_flag 253, 1
event_626_command_87F0:
    event_set_flag 254, 6
event_626_command_87F3:
    event_set_flag 11, 4
event_626_command_87F6:
    event_jump 1811
event_626_command_87F8:
    event_end 
event_627_command_87F9:
    event_set_flag 253, 1
event_627_command_87FC:
    event_set_flag 254, 7
event_627_command_87FF:
    event_jump 1829
event_627_command_8801:
    event_end 
event_628_command_8802:
    event_set_flag 253, 1
event_628_command_8805:
    event_set_flag 254, 8
event_628_command_8808:
    event_test_flag_range 65, 0, 0
event_628_command_880B:
    event_jump 1199
event_628_command_880D:
    event_jump 1794
event_628_command_880F:
    event_end 
event_629_command_8810:
    event_set_flag 253, 1
event_629_command_8813:
    event_set_flag 254, 9
event_629_command_8816:
    event_jump 1808
event_629_command_8818:
    event_end 
event_62A_command_8819:
    event_set_flag 253, 1
event_62A_command_881C:
    event_set_flag 254, 10
event_62A_command_881F:
    event_test_flag_range 93, 0, 0
event_62A_command_8822:
    event_call 1240
event_62A_command_8824:
    event_jump 1831
event_62A_command_8826:
    event_end 
event_62B_command_8827:
    event_test_flag_range 70, 0, 7
event_62B_command_882A:
    event_jump 1624
event_62B_command_882C:
    event_set_flag 253, 1
event_62B_command_882F:
    event_set_flag 254, 11
event_62B_command_8832:
    event_jump 1830
event_62B_command_8834:
    event_end 
event_62C_command_8835:
    event_set_flag 253, 1
event_62C_command_8838:
    event_set_flag 254, 12
event_62C_command_883B:
    event_jump 1830
event_62C_command_883D:
    event_end 
event_62D_command_883E:
    event_set_flag 253, 1
event_62D_command_8841:
    event_set_flag 254, 13
event_62D_command_8844:
    event_jump 1834
event_62D_command_8846:
    event_end 
event_62E_command_8847:
    event_set_flag 253, 1
event_62E_command_884A:
    event_set_flag 254, 14
event_62E_command_884D:
    event_jump 1806
event_62E_command_884F:
    event_end 
event_62F_command_8850:
    event_end 
event_630_command_8851:
    event_end 
event_631_command_8852:
    event_end 
event_632_command_8853:
    event_set_flag 86, 2
event_632_command_8856:
    event_return 
event_632_command_8857:
    event_end 
event_633_command_8858:
    event_set_flag 253, 1
event_633_command_885B:
    event_set_flag 254, 13
event_633_command_885E:
    event_set_flag 11, 2
event_633_command_8861:
    event_jump 1828
event_633_command_8863:
    event_end 
event_634_command_8864:
    event_end 
event_635_command_8865:
    event_end 
event_636_command_8866:
    event_test_flag_range 38, 0, 5
event_636_command_8869:
    event_call 1591
event_636_command_886B:
    event_test_flag_range 86, 3, 4
event_636_command_886E:
    event_call 1586
event_636_command_8870:
    event_jump 1813
event_636_command_8872:
    event_end 
event_637_command_8873:
    event_set_flag 11, 3
event_637_command_8876:
    event_return 
event_637_command_8877:
    event_end 
event_638_command_8878:
    event_jump 1807
event_638_command_887A:
    event_end 
event_639_command_887B:
    event_end 
event_63A_command_887C:
    event_test_flag_range 59, 0, 1
event_63A_command_887F:
    event_call 1996
event_63A_command_8881:
    event_test_flag_range 59, 2, 15
event_63A_command_8884:
    event_call 2002
event_63A_command_8886:
    event_end 
event_63B_command_8887:
    event_test_flag_range 174, 0, 1
event_63B_command_888A:
    event_call 1993
event_63B_command_888C:
    event_test_flag_range 174, 2, 15
event_63B_command_888F:
    event_call 2002
event_63B_command_8891:
    event_end 
event_63C_command_8892:
    event_end 
event_63D_command_8893:
    event_call 2002
event_63D_command_8895:
    event_test_flag_range 44, 1, 15
event_63D_command_8898:
    event_jump 0
event_63D_command_889A:
    event_screen_word 6, 31
