.setcpu "65816"
.segment "CODE"
.org $A773
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_585e:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $585E, $586C
ai_pc_5863:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_5867:
    ai_cmd81_ef $0005, $00EA
ai_pc_586a:
    ai_jmp_01_short $586A, $5871
ai_pc_586c:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_5870:
    ai_cmd04_ee
ai_pc_5871:
    ai_ret_00
ai_pc_5872:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $5872, $5880
ai_pc_5877:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_587b:
    ai_cmd81_ef $0005, $00EA
ai_pc_587e:
    ai_jmp_01_short $587E, $5885
ai_pc_5880:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_5884:
    ai_cmd04_ee
ai_pc_5885:
    ai_ret_00
ai_pc_5886:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $5886, $5894
ai_pc_588b:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_588f:
    ai_cmd81_ef $0005, $00EA
ai_pc_5892:
    ai_jmp_01_short $5892, $5899
ai_pc_5894:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_5898:
    ai_cmd04_ee
ai_pc_5899:
    ai_ret_00
ai_pc_589a:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $589A, $58A8
ai_pc_589f:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_58a3:
    ai_cmd81_ef $0005, $00EA
ai_pc_58a6:
    ai_jmp_01_short $58A6, $58AD
ai_pc_58a8:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_58ac:
    ai_cmd04_ee
ai_pc_58ad:
    ai_ret_00
ai_pc_58ae:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $58AE, $58BC
ai_pc_58b3:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_58b7:
    ai_cmd81_ef $0005, $00EA
ai_pc_58ba:
    ai_jmp_01_short $58BA, $58C1
ai_pc_58bc:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_58c0:
    ai_cmd04_ee
ai_pc_58c1:
    ai_ret_00
ai_pc_58c2:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $58C2, $58D0
ai_pc_58c7:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_58cb:
    ai_cmd81_ef $0005, $00EA
ai_pc_58ce:
    ai_jmp_01_short $58CE, $58D5
ai_pc_58d0:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_58d4:
    ai_cmd04_ee
ai_pc_58d5:
    ai_ret_00
ai_pc_58d6:
    ai_if_field_and_z_2e_short $0080, $0031, $0080, $58D6, $58E4
ai_pc_58db:
    ai_hop_e0 $0008, $0000, $0000
ai_pc_58df:
    ai_cmd81_ef $0005, $00EA
ai_pc_58e2:
    ai_jmp_01_short $58E2, $58E9
ai_pc_58e4:
    ai_hop_e0 $0004, $0000, $0000
ai_pc_58e8:
    ai_cmd04_ee
ai_pc_58e9:
    ai_ret_00
