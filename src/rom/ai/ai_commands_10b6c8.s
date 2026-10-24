.setcpu "65816"
.segment "CODE"
.org $B6C8
.include "ai_command_macros.inc"
ai_pc_67b3:
    ai_rnd_var3_2c $0003
ai_pc_67b5:
    ai_set_var2_27 $0002
ai_pc_67b7:
    ai_pos_save_9f
ai_pc_67b8:
    ai_if_var3_nz_05_short $67B8, $67C0
ai_pc_67ba:
    ai_hop_e0 $0008, $0001, $000A
ai_pc_67be:
    ai_jmp_01_short $67BE, $67D6
ai_pc_67c0:
    ai_if_var3_ne_0d_short $0001, $67C0, $67C9
ai_pc_67c3:
    ai_hop_e0 $0004, $0001, $000A
ai_pc_67c7:
    ai_jmp_01_short $67C7, $67D6
ai_pc_67c9:
    ai_if_var3_ne_0d_short $0002, $67C9, $67D2
ai_pc_67cc:
    ai_hop_e0 $0001, $0001, $000A
ai_pc_67d0:
    ai_jmp_01_short $67D0, $67D6
ai_pc_67d2:
    ai_hop_e0 $0002, $0001, $000A
ai_pc_67d6:
    ai_if_pos_moved_9e_short $67D6, $67DB
ai_pc_67d8:
    ai_jmp_01_long $67D8, $67DE
ai_pc_67db:
    ai_dec_var2_20
ai_pc_67dc:
    ai_if_var2_nz_04_short $67DC, $67B7
ai_pc_67de:
    ai_ret_00
ai_pc_67df:
    ai_rnd_var3_2c $0002
ai_pc_67e1:
    ai_if_var3_nz_05_short $67E1, $6800
ai_pc_67e3:
    ai_rnd_var3_2c $0007
ai_pc_67e5:
    ai_if_var3_nz_05_short $67E5, $67EC
ai_pc_67e7:
    ai_call_ff $683C
ai_pc_67ea:
    ai_jmp_01_short $67EA, $67FE
ai_pc_67ec:
    ai_rnd_var3_2c $0004
ai_pc_67ee:
    ai_if_var3_nz_05_short $67EE, $67FB
ai_pc_67f0:
    ai_turn_facing_e3 $0000, $0000
ai_pc_67f3:
    ai_turn_facing_e3 $0000, $0000
ai_pc_67f6:
    ai_turn_facing_e3 $0000, $0000
ai_pc_67f9:
    ai_jmp_01_short $67F9, $67FE
ai_pc_67fb:
    ai_call_ff $685D
ai_pc_67fe:
    ai_jmp_01_short $67FE, $683B
ai_pc_6800:
    ai_if_var3_ne_0d_short $0001, $6800, $6820
ai_pc_6803:
    ai_rnd_var3_2c $0007
ai_pc_6805:
    ai_if_var3_nz_05_short $6805, $680C
ai_pc_6807:
    ai_call_ff $687E
ai_pc_680a:
    ai_jmp_01_short $680A, $681E
ai_pc_680c:
    ai_rnd_var3_2c $0004
ai_pc_680e:
    ai_if_var3_nz_05_short $680E, $681B
ai_pc_6810:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6813:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6816:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6819:
    ai_jmp_01_short $6819, $681E
ai_pc_681b:
    ai_call_ff $689F
ai_pc_681e:
    ai_jmp_01_short $681E, $683B
ai_pc_6820:
    ai_rnd_var3_2c $0007
ai_pc_6822:
    ai_if_var3_nz_05_short $6822, $6829
ai_pc_6824:
    ai_call_ff $68C0
ai_pc_6827:
    ai_jmp_01_short $6827, $683B
ai_pc_6829:
    ai_rnd_var3_2c $0004
ai_pc_682b:
    ai_if_var3_nz_05_short $682B, $6838
ai_pc_682d:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6830:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6833:
    ai_turn_facing_e3 $0000, $0000
ai_pc_6836:
    ai_jmp_01_short $6836, $683B
ai_pc_6838:
    ai_call_ff $68E1
ai_pc_683b:
    ai_ret_00
ai_pc_683c:
    ai_rnd_var3_2c $0003
ai_pc_683e:
    ai_if_var3_nz_05_short $683E, $6846
ai_pc_6840:
    ai_hop_e0 $0009, $0004, $0000
ai_pc_6844:
    ai_jmp_01_short $6844, $685C
ai_pc_6846:
    ai_if_var3_ne_0d_short $0001, $6846, $684F
ai_pc_6849:
    ai_hop_e0 $000A, $0004, $0000
ai_pc_684d:
    ai_jmp_01_short $684D, $685C
ai_pc_684f:
    ai_if_var3_ne_0d_short $0002, $684F, $6858
ai_pc_6852:
    ai_hop_e0 $0005, $0004, $0000
ai_pc_6856:
    ai_jmp_01_short $6856, $685C
ai_pc_6858:
    ai_hop_e0 $0006, $0004, $0000
ai_pc_685c:
    ai_ret_00
ai_pc_685d:
    ai_rnd_var3_2c $0003
ai_pc_685f:
    ai_if_var3_nz_05_short $685F, $6867
ai_pc_6861:
    ai_hop_e0 $0008, $0004, $0000
ai_pc_6865:
    ai_jmp_01_short $6865, $687D
ai_pc_6867:
    ai_if_var3_ne_0d_short $0001, $6867, $6870
ai_pc_686a:
    ai_hop_e0 $0004, $0004, $0000
ai_pc_686e:
    ai_jmp_01_short $686E, $687D
ai_pc_6870:
    ai_if_var3_ne_0d_short $0002, $6870, $6879
ai_pc_6873:
    ai_hop_e0 $0001, $0004, $0000
ai_pc_6877:
    ai_jmp_01_short $6877, $687D
ai_pc_6879:
    ai_hop_e0 $0002, $0004, $0000
ai_pc_687d:
    ai_ret_00
ai_pc_687e:
    ai_rnd_var3_2c $0003
ai_pc_6880:
    ai_if_var3_nz_05_short $6880, $6888
ai_pc_6882:
    ai_hop_e0 $0009, $0001, $0000
ai_pc_6886:
    ai_jmp_01_short $6886, $689E
ai_pc_6888:
    ai_if_var3_ne_0d_short $0001, $6888, $6891
ai_pc_688b:
    ai_hop_e0 $000A, $0001, $0000
ai_pc_688f:
    ai_jmp_01_short $688F, $689E
ai_pc_6891:
    ai_if_var3_ne_0d_short $0002, $6891, $689A
ai_pc_6894:
    ai_hop_e0 $0005, $0001, $0000
ai_pc_6898:
    ai_jmp_01_short $6898, $689E
ai_pc_689a:
    ai_hop_e0 $0006, $0001, $0000
ai_pc_689e:
    ai_ret_00
ai_pc_689f:
    ai_rnd_var3_2c $0003
ai_pc_68a1:
    ai_if_var3_nz_05_short $68A1, $68A9
ai_pc_68a3:
    ai_hop_e0 $0008, $0001, $0000
ai_pc_68a7:
    ai_jmp_01_short $68A7, $68BF
ai_pc_68a9:
    ai_if_var3_ne_0d_short $0001, $68A9, $68B2
ai_pc_68ac:
    ai_hop_e0 $0004, $0001, $0000
ai_pc_68b0:
    ai_jmp_01_short $68B0, $68BF
ai_pc_68b2:
    ai_if_var3_ne_0d_short $0002, $68B2, $68BB
ai_pc_68b5:
    ai_hop_e0 $0001, $0001, $0000
ai_pc_68b9:
    ai_jmp_01_short $68B9, $68BF
ai_pc_68bb:
    ai_hop_e0 $0002, $0001, $0000
ai_pc_68bf:
    ai_ret_00
ai_pc_68c0:
    ai_rnd_var3_2c $0003
ai_pc_68c2:
    ai_if_var3_nz_05_short $68C2, $68CA
ai_pc_68c4:
    ai_hop_e0 $0009, $0002, $0000
ai_pc_68c8:
    ai_jmp_01_short $68C8, $68E0
ai_pc_68ca:
    ai_if_var3_ne_0d_short $0001, $68CA, $68D3
ai_pc_68cd:
    ai_hop_e0 $000A, $0002, $0000
ai_pc_68d1:
    ai_jmp_01_short $68D1, $68E0
ai_pc_68d3:
    ai_if_var3_ne_0d_short $0002, $68D3, $68DC
ai_pc_68d6:
    ai_hop_e0 $0005, $0002, $0000
ai_pc_68da:
    ai_jmp_01_short $68DA, $68E0
ai_pc_68dc:
    ai_hop_e0 $0006, $0002, $0000
ai_pc_68e0:
    ai_ret_00
ai_pc_68e1:
    ai_rnd_var3_2c $0003
ai_pc_68e3:
    ai_if_var3_nz_05_short $68E3, $68EB
ai_pc_68e5:
    ai_hop_e0 $0008, $0002, $0000
ai_pc_68e9:
    ai_jmp_01_short $68E9, $6901
ai_pc_68eb:
    ai_if_var3_ne_0d_short $0001, $68EB, $68F4
ai_pc_68ee:
    ai_hop_e0 $0004, $0002, $0000
ai_pc_68f2:
    ai_jmp_01_short $68F2, $6901
ai_pc_68f4:
    ai_if_var3_ne_0d_short $0002, $68F4, $68FD
ai_pc_68f7:
    ai_hop_e0 $0001, $0002, $0000
ai_pc_68fb:
    ai_jmp_01_short $68FB, $6901
ai_pc_68fd:
    ai_hop_e0 $0002, $0002, $0000
ai_pc_6901:
    ai_ret_00
ai_pc_6902:
    ai_if_pos_same_9d_short $6902, $690A
ai_pc_6904:
    ai_pos_save_9f
ai_pc_6905:
    ai_move_toward_e4 $0002, $0000
ai_pc_6908:
    ai_jmp_01_short $6908, $690E
ai_pc_690a:
    ai_pos_save_9f
ai_pc_690b:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_690e:
    ai_ret_00
ai_pc_690f:
    ai_rnd_var3_2c $0003
ai_pc_6911:
    ai_set_var2_27 $0004
ai_pc_6913:
    ai_pos_save_9f
ai_pc_6914:
    ai_if_var3_nz_05_short $6914, $691C
ai_pc_6916:
    ai_hop_e0 $0009, $0004, $000F
ai_pc_691a:
    ai_jmp_01_short $691A, $6932
ai_pc_691c:
    ai_if_var3_ne_0d_short $0001, $691C, $6925
ai_pc_691f:
    ai_hop_e0 $000A, $0004, $000F
ai_pc_6923:
    ai_jmp_01_short $6923, $6932
ai_pc_6925:
    ai_if_var3_ne_0d_short $0002, $6925, $692E
ai_pc_6928:
    ai_hop_e0 $0005, $0004, $000F
ai_pc_692c:
    ai_jmp_01_short $692C, $6932
ai_pc_692e:
    ai_hop_e0 $0006, $0004, $000F
ai_pc_6932:
    ai_if_pos_moved_9e_short $6932, $6937
ai_pc_6934:
    ai_jmp_01_long $6934, $693A
ai_pc_6937:
    ai_dec_var2_20
ai_pc_6938:
    ai_if_var2_nz_04_short $6938, $6913
ai_pc_693a:
    ai_ret_00
ai_pc_693b:
    ai_rnd_var3_2c $0003
ai_pc_693d:
    ai_set_var2_27 $0004
ai_pc_693f:
    ai_pos_save_9f
ai_pc_6940:
    ai_if_var3_nz_05_short $6940, $6948
ai_pc_6942:
    ai_hop_e0 $0008, $0004, $000F
ai_pc_6946:
    ai_jmp_01_short $6946, $695E
ai_pc_6948:
    ai_if_var3_ne_0d_short $0001, $6948, $6951
ai_pc_694b:
    ai_hop_e0 $0004, $0004, $000F
ai_pc_694f:
    ai_jmp_01_short $694F, $695E
ai_pc_6951:
    ai_if_var3_ne_0d_short $0002, $6951, $695A
ai_pc_6954:
    ai_hop_e0 $0001, $0004, $000F
ai_pc_6958:
    ai_jmp_01_short $6958, $695E
ai_pc_695a:
    ai_hop_e0 $0002, $0004, $000F
ai_pc_695e:
    ai_if_pos_moved_9e_short $695E, $6963
ai_pc_6960:
    ai_jmp_01_long $6960, $6966
ai_pc_6963:
    ai_dec_var2_20
ai_pc_6964:
    ai_if_var2_nz_04_short $6964, $693F
ai_pc_6966:
    ai_ret_00
