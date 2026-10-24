.setcpu "65816"
.segment "RODATA"
.org $BDC1
boss_attack_numeric_records:
boss_attack_numeric_record_00:
    .word $0000 ; attack flags
    .byte $63, $23 ; accuracy, power
    .word $4000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_01:
    .word $0000 ; attack flags
    .byte $63, $22 ; accuracy, power
    .word $0020 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_02:
    .word $0000 ; attack flags
    .byte $63, $7D ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_03:
    .word $0000 ; attack flags
    .byte $63, $0C ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_04:
    .word $0000 ; attack flags
    .byte $63, $00 ; accuracy, power
    .word $2000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_05:
    .word $0000 ; attack flags
    .byte $63, $25 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_06:
    .word $0000 ; attack flags
    .byte $63, $00 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_07:
    .word $0000 ; attack flags
    .byte $63, $41 ; accuracy, power
    .word $0040 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_08:
    .word $0000 ; attack flags
    .byte $63, $21 ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_09:
    .word $0000 ; attack flags
    .byte $63, $36 ; accuracy, power
    .word $2000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_0a:
    .word $0000 ; attack flags
    .byte $63, $0B ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_0b:
    .word $0000 ; attack flags
    .byte $63, $0B ; accuracy, power
    .word $4000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_0c:
    .word $0000 ; attack flags
    .byte $63, $1D ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_0d:
    .word $0000 ; attack flags
    .byte $63, $7C ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_0e:
    .word $0000 ; attack flags
    .byte $63, $5D ; accuracy, power
    .word $0020 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_0f:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0040 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_10:
    .word $0000 ; attack flags
    .byte $63, $00 ; accuracy, power
    .word $1000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_11:
    .word $0000 ; attack flags
    .byte $63, $25 ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_12:
    .word $0000 ; attack flags
    .byte $63, $43 ; accuracy, power
    .word $0100 ; status mask
    .byte $50 ; status chance
boss_attack_numeric_record_13:
    .word $0000 ; attack flags
    .byte $63, $51 ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_14:
    .word $0000 ; attack flags
    .byte $63, $00 ; accuracy, power
    .word $0010 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_15:
    .word $0000 ; attack flags
    .byte $63, $16 ; accuracy, power
    .word $1000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_16:
    .word $0000 ; attack flags
    .byte $63, $47 ; accuracy, power
    .word $0200 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_17:
    .word $0000 ; attack flags
    .byte $63, $16 ; accuracy, power
    .word $0004 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_18:
    .word $0000 ; attack flags
    .byte $63, $19 ; accuracy, power
    .word $1200 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_19:
    .word $0000 ; attack flags
    .byte $63, $5D ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_1a:
    .word $0000 ; attack flags
    .byte $63, $45 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_1b:
    .word $0000 ; attack flags
    .byte $4B, $11 ; accuracy, power
    .word $0010 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_1c:
    .word $0000 ; attack flags
    .byte $63, $1E ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_1d:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_1e:
    .word $0000 ; attack flags
    .byte $63, $19 ; accuracy, power
    .word $2000 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_1f:
    .word $0000 ; attack flags
    .byte $63, $46 ; accuracy, power
    .word $2000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_20:
    .word $0000 ; attack flags
    .byte $63, $20 ; accuracy, power
    .word $0000 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_21:
    .word $0000 ; attack flags
    .byte $63, $22 ; accuracy, power
    .word $0010 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_22:
    .word $0000 ; attack flags
    .byte $63, $24 ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_23:
    .word $0000 ; attack flags
    .byte $63, $21 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_24:
    .word $0000 ; attack flags
    .byte $63, $23 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_25:
    .word $0000 ; attack flags
    .byte $63, $26 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_26:
    .word $0000 ; attack flags
    .byte $63, $34 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_27:
    .word $0000 ; attack flags
    .byte $63, $46 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_28:
    .word $0000 ; attack flags
    .byte $63, $54 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_29:
    .word $0000 ; attack flags
    .byte $63, $5E ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_2a:
    .word $0000 ; attack flags
    .byte $63, $55 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_2b:
    .word $0000 ; attack flags
    .byte $63, $62 ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_2c:
    .word $0000 ; attack flags
    .byte $63, $5E ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_2d:
    .word $0000 ; attack flags
    .byte $63, $67 ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_2e:
    .word $0000 ; attack flags
    .byte $63, $23 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_2f:
    .word $0000 ; attack flags
    .byte $63, $30 ; accuracy, power
    .word $1000 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_30:
    .word $0000 ; attack flags
    .byte $63, $2B ; accuracy, power
    .word $1000 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_31:
    .word $0000 ; attack flags
    .byte $63, $34 ; accuracy, power
    .word $1000 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_32:
    .word $0000 ; attack flags
    .byte $63, $6A ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_33:
    .word $0000 ; attack flags
    .byte $63, $61 ; accuracy, power
    .word $0010 ; status mask
    .byte $19 ; status chance
boss_attack_numeric_record_34:
    .word $0000 ; attack flags
    .byte $63, $6F ; accuracy, power
    .word $0010 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_35:
    .word $0000 ; attack flags
    .byte $63, $28 ; accuracy, power
    .word $4000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_36:
    .word $0000 ; attack flags
    .byte $63, $78 ; accuracy, power
    .word $4000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_37:
    .word $0000 ; attack flags
    .byte $63, $78 ; accuracy, power
    .word $0020 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_38:
    .word $0000 ; attack flags
    .byte $63, $14 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_39:
    .word $0000 ; attack flags
    .byte $63, $30 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_3a:
    .word $0000 ; attack flags
    .byte $63, $44 ; accuracy, power
    .word $0040 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_3b:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_3c:
    .word $0000 ; attack flags
    .byte $63, $28 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_3d:
    .word $0000 ; attack flags
    .byte $63, $3B ; accuracy, power
    .word $0200 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_3e:
    .word $0000 ; attack flags
    .byte $63, $32 ; accuracy, power
    .word $1200 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_3f:
    .word $0000 ; attack flags
    .byte $63, $2C ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_40:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $2000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_41:
    .word $0000 ; attack flags
    .byte $63, $2E ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_42:
    .word $0000 ; attack flags
    .byte $63, $24 ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_43:
    .word $0000 ; attack flags
    .byte $63, $32 ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_44:
    .word $0000 ; attack flags
    .byte $63, $07 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_45:
    .word $0000 ; attack flags
    .byte $63, $07 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_46:
    .word $0000 ; attack flags
    .byte $63, $3C ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_47:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0080 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_48:
    .word $0000 ; attack flags
    .byte $63, $22 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_49:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0100 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_4a:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0200 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_4b:
    .word $0000 ; attack flags
    .byte $63, $4C ; accuracy, power
    .word $0004 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_4c:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0004 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_4d:
    .word $0000 ; attack flags
    .byte $63, $4C ; accuracy, power
    .word $2000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_4e:
    .word $0000 ; attack flags
    .byte $63, $55 ; accuracy, power
    .word $0010 ; status mask
    .byte $21 ; status chance
boss_attack_numeric_record_4f:
    .word $0000 ; attack flags
    .byte $63, $64 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_50:
    .word $0000 ; attack flags
    .byte $63, $51 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_51:
    .word $0000 ; attack flags
    .byte $63, $51 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_52:
    .word $0000 ; attack flags
    .byte $63, $5F ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_53:
    .word $0000 ; attack flags
    .byte $63, $58 ; accuracy, power
    .word $0000 ; status mask
    .byte $42 ; status chance
boss_attack_numeric_record_54:
    .word $0000 ; attack flags
    .byte $63, $58 ; accuracy, power
    .word $2000 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_55:
    .word $0000 ; attack flags
    .byte $63, $58 ; accuracy, power
    .word $4000 ; status mask
    .byte $42 ; status chance
boss_attack_numeric_record_56:
    .word $0000 ; attack flags
    .byte $63, $58 ; accuracy, power
    .word $0020 ; status mask
    .byte $42 ; status chance
boss_attack_numeric_record_57:
    .word $0000 ; attack flags
    .byte $4B, $1E ; accuracy, power
    .word $0200 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_58:
    .word $0000 ; attack flags
    .byte $4B, $1E ; accuracy, power
    .word $0010 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_59:
    .word $0000 ; attack flags
    .byte $4B, $1E ; accuracy, power
    .word $0200 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_5a:
    .word $0000 ; attack flags
    .byte $4B, $1E ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_5b:
    .word $0000 ; attack flags
    .byte $63, $65 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_5c:
    .word $0000 ; attack flags
    .byte $63, $78 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_5d:
    .word $0000 ; attack flags
    .byte $63, $6E ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_5e:
    .word $0000 ; attack flags
    .byte $63, $6E ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_5f:
    .word $0000 ; attack flags
    .byte $63, $78 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_60:
    .word $0000 ; attack flags
    .byte $63, $21 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_61:
    .word $0000 ; attack flags
    .byte $63, $2A ; accuracy, power
    .word $0010 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_62:
    .word $0000 ; attack flags
    .byte $63, $25 ; accuracy, power
    .word $2000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_63:
    .word $0000 ; attack flags
    .byte $63, $0A ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_64:
    .word $0000 ; attack flags
    .byte $63, $47 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_65:
    .word $0000 ; attack flags
    .byte $63, $51 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_66:
    .word $0000 ; attack flags
    .byte $63, $51 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_67:
    .word $0000 ; attack flags
    .byte $63, $7B ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_68:
    .word $0000 ; attack flags
    .byte $63, $37 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_69:
    .word $0000 ; attack flags
    .byte $63, $37 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_6a:
    .word $0000 ; attack flags
    .byte $63, $37 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_6b:
    .word $0000 ; attack flags
    .byte $63, $37 ; accuracy, power
    .word $0020 ; status mask
    .byte $42 ; status chance
boss_attack_numeric_record_6c:
    .word $0000 ; attack flags
    .byte $63, $37 ; accuracy, power
    .word $4000 ; status mask
    .byte $42 ; status chance
boss_attack_numeric_record_6d:
    .word $0000 ; attack flags
    .byte $63, $7D ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_6e:
    .word $0000 ; attack flags
    .byte $63, $7F ; accuracy, power
    .word $0010 ; status mask
    .byte $63 ; status chance
boss_attack_numeric_record_6f:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_70:
    .word $0000 ; attack flags
    .byte $63, $59 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_71:
    .word $0000 ; attack flags
    .byte $63, $5C ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
boss_attack_numeric_record_72:
    .word $0000 ; attack flags
    .byte $63, $78 ; accuracy, power
    .word $0000 ; status mask
    .byte $32 ; status chance
