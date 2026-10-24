; Four numeric palette resource IDs per native selector; pointed colors excluded.
.setcpu "65816"
.segment "CODE"
.org $2E00
.macro object_palette_ids row_82_id, row_a2_id, row_c2_id, row_e2_id
    .byte row_82_id, row_a2_id, row_c2_id, row_e2_id
.endmacro
map_map_control_remaining_20261013_object_palette_ids:
map_map_control_remaining_20261013_selector_00:
    object_palette_ids $83, $84, $85, $86
map_map_control_remaining_20261013_selector_01:
    object_palette_ids $80, $81, $82, $83
map_map_control_remaining_20261013_selector_02:
    object_palette_ids $80, $C0, $D8, $C1
map_map_control_remaining_20261013_selector_03:
    object_palette_ids $83, $C5, $C7, $C8
map_map_control_remaining_20261013_selector_04:
    object_palette_ids $C5, $C7, $C8, $CA
map_map_control_remaining_20261013_selector_05:
    object_palette_ids $06, $25, $06, $25
map_map_control_remaining_20261013_selector_06:
    object_palette_ids $98, $99, $9B, $9C
map_map_control_remaining_20261013_selector_07:
    object_palette_ids $9D, $A0, $A1, $A3
map_map_control_remaining_20261013_selector_08:
    object_palette_ids $A6, $A8, $A9, $AA
map_map_control_remaining_20261013_selector_09:
    object_palette_ids $C2, $C3, $CB, $CE
map_map_control_remaining_20261013_selector_0a:
    object_palette_ids $C4, $C5, $C6, $C7
map_map_control_remaining_20261013_selector_0b:
    object_palette_ids $C8, $C9, $CA, $C4
map_map_control_remaining_20261013_selector_0c:
    object_palette_ids $9E, $E1, $E0, $CD
map_map_control_remaining_20261013_selector_0d:
    object_palette_ids $55, $55, $55, $55
map_map_control_remaining_20261013_selector_0e:
    object_palette_ids $D9, $DA, $CB, $CE
map_map_control_remaining_20261013_selector_0f:
    object_palette_ids $C5, $C6, $C4, $CF
map_map_control_remaining_20261013_selector_10:
    object_palette_ids $C0, $C1, $C5, $A0
map_map_control_remaining_20261013_selector_11:
    object_palette_ids $C5, $C6, $CF, $A0
map_map_control_remaining_20261013_selector_12:
    object_palette_ids $AC, $B7, $99, $A0
map_map_control_remaining_20261013_selector_13:
    object_palette_ids $A1, $B1, $DF, $A0
map_map_control_remaining_20261013_selector_14:
    object_palette_ids $A1, $B1, $DF, $B6
map_map_control_remaining_20261013_selector_15:
    object_palette_ids $C5, $C6, $EA, $A0
map_map_control_remaining_20261013_selector_16:
    object_palette_ids $81, $06, $A0, $A0
map_map_control_remaining_20261013_selector_17:
    object_palette_ids $B7, $C5, $A6, $BC
map_map_control_remaining_20261013_selector_18:
    object_palette_ids $CF, $A6, $C5, $C6
map_map_control_remaining_20261013_selector_19:
    object_palette_ids $BB, $A6, $C5, $81
map_map_control_remaining_20261013_selector_1a:
    object_palette_ids $A0, $BD, $BC, $B7
map_map_control_remaining_20261013_selector_1b:
    object_palette_ids $9A, $9C, $9B, $82
map_map_control_remaining_20261013_selector_1c:
    object_palette_ids $00, $9B, $C6, $82
map_map_control_remaining_20261013_selector_1d:
    object_palette_ids $B7, $EA, $C4, $BC
map_map_control_remaining_20261013_selector_1e:
    object_palette_ids $B7, $81, $BB, $BC
map_map_control_remaining_20261013_selector_1f:
    object_palette_ids $A9, $A6, $C8, $C9
map_map_control_remaining_20261013_selector_20:
    object_palette_ids $BF, $A6, $AC, $A9
map_map_control_remaining_20261013_selector_21:
    object_palette_ids $CF, $C6, $CE, $CA
map_map_control_remaining_20261013_selector_22:
    object_palette_ids $91, $91, $91, $91
map_map_control_remaining_20261013_selector_23:
    object_palette_ids $9C, $9F, $9F, $9F
map_map_control_remaining_20261013_selector_24:
    object_palette_ids $9E, $E1, $E2, $E3
map_map_control_remaining_20261013_selector_25:
    object_palette_ids $E1, $E2, $E3, $9C
map_map_control_remaining_20261013_selector_26:
    object_palette_ids $DF, $A4, $A5, $A0
map_map_control_remaining_20261013_selector_27:
    object_palette_ids $9C, $99, $98, $EA
map_map_control_remaining_20261013_selector_28:
    object_palette_ids $B9, $B7, $C4, $A8
map_map_control_remaining_20261013_selector_29:
    object_palette_ids $B9, $B7, $C4, $82
map_map_control_remaining_20261013_selector_2a:
    object_palette_ids $B9, $B7, $B8, $81
map_map_control_remaining_20261013_selector_2b:
    object_palette_ids $B1, $B7, $B6, $B6
map_map_control_remaining_20261013_selector_2c:
    object_palette_ids $B9, $B7, $B8, $A8
map_map_control_remaining_20261013_selector_2d:
    object_palette_ids $CF, $CA, $CF, $9C
map_map_control_remaining_20261013_selector_2e:
    object_palette_ids $92, $DD, $A5, $C9
map_map_control_remaining_20261013_selector_2f:
    object_palette_ids $A4, $DD, $A5, $C9
map_map_control_remaining_20261013_selector_30:
    object_palette_ids $CA, $BB, $A5, $C9
map_map_control_remaining_20261013_selector_31:
    object_palette_ids $CF, $C8, $C9, $A5
map_map_control_remaining_20261013_selector_32:
    object_palette_ids $AD, $AE, $EA, $DF
map_map_control_remaining_20261013_selector_33:
    object_palette_ids $CB, $B6, $C5, $C2
map_map_control_remaining_20261013_selector_34:
    object_palette_ids $C6, $C4, $B6, $CF
map_map_control_remaining_20261013_selector_35:
    object_palette_ids $A7, $C3, $C2, $C5
map_map_control_remaining_20261013_selector_36:
    object_palette_ids $B0, $C3, $C2, $B6
map_map_control_remaining_20261013_selector_37:
    object_palette_ids $A7, $C3, $C2, $B6
map_map_control_remaining_20261013_selector_38:
    object_palette_ids $B0, $B1, $B2, $B4
map_map_control_remaining_20261013_selector_39:
    object_palette_ids $BD, $B7, $CF, $A0
map_map_control_remaining_20261013_selector_3a:
    object_palette_ids $B7, $BC, $C6, $C7
map_map_control_remaining_20261013_selector_3b:
    object_palette_ids $C4, $BC, $B6, $CF
map_map_control_remaining_20261013_selector_3c:
    object_palette_ids $9C, $BD, $CF, $C6
map_map_control_remaining_20261013_selector_3d:
    object_palette_ids $C5, $AA, $C7, $D2
map_map_control_remaining_20261013_selector_3e:
    object_palette_ids $9A, $A0, $9B, $82
map_map_control_remaining_20261013_selector_3f:
    object_palette_ids $B7, $C4, $BC, $A0
map_map_control_remaining_20261013_selector_40:
    object_palette_ids $D2, $BB, $C4, $C9
map_map_control_remaining_20261013_selector_41:
    object_palette_ids $C5, $B7, $C7, $CF
map_map_control_remaining_20261013_selector_42:
    object_palette_ids $B7, $BC, $C6, $A0
map_map_control_remaining_20261013_selector_43:
    object_palette_ids $BB, $C6, $C5, $CF
map_map_control_remaining_20261013_selector_44:
    object_palette_ids $C6, $A6, $9C, $CF
map_map_control_remaining_20261013_selector_45:
    object_palette_ids $B9, $B8, $A8, $B7
map_map_control_remaining_20261013_selector_46:
    object_palette_ids $A7, $C3, $C2, $CB
map_map_control_remaining_20261013_selector_47:
    object_palette_ids $A3, $A4, $A5, $00
map_map_control_remaining_20261013_selector_48:
    object_palette_ids $CA, $0D, $0D, $0D
map_map_control_remaining_20261013_selector_49:
    object_palette_ids $99, $00, $00, $00
map_map_control_remaining_20261013_selector_4a:
    object_palette_ids $D8, $D8, $D8, $D8
map_map_control_remaining_20261013_selector_4b:
    object_palette_ids $C0, $C1, $C5, $C6
map_map_control_remaining_20261013_selector_4c:
    object_palette_ids $CC, $CC, $CC, $CC
map_map_control_remaining_20261013_selector_4d:
    object_palette_ids $9E, $E0, $E3, $E1
map_map_control_remaining_20261013_selector_4e:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_4f:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_50:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_51:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_52:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_53:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_54:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_55:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_56:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_57:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_58:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_59:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_5a:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_5b:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_5c:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_5d:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_5e:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_5f:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_60:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_61:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_62:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_63:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_64:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_65:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_66:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_67:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_68:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_69:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_6a:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_6b:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_6c:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_6d:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_6e:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_6f:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_70:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_71:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_72:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_73:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_74:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_75:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_76:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_77:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_78:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_79:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_7a:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_7b:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_7c:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_7d:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_7e:
    object_palette_ids $FF, $FF, $FF, $FF
map_map_control_remaining_20261013_selector_7f:
    object_palette_ids $FF, $FF, $FF, $FF
