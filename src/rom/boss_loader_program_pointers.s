; Boss identity 54..7F list offsets in bank C1; no script payload.
.setcpu "65816"
boss_loader_list_54 = $626F
boss_loader_list_55 = $62F2
boss_loader_list_56 = $62F2
boss_loader_list_57 = $61CB
boss_loader_list_58 = $6346
boss_loader_list_59 = $626F
boss_loader_list_5a = $624D
boss_loader_list_5b = $62D0
boss_loader_list_5c = $61EF
boss_loader_list_5d = $6382
boss_loader_list_5e = $6310
boss_loader_list_5f = $6301
boss_loader_list_60 = $63A4
boss_loader_list_61 = $6364
boss_loader_list_62 = $63E6
boss_loader_list_63 = $61DF
boss_loader_list_64 = $63BA
boss_loader_list_65 = $6211
boss_loader_list_66 = $625E
boss_loader_list_67 = $626F
boss_loader_list_68 = $6292
boss_loader_list_69 = $6413
boss_loader_list_6a = $6431
boss_loader_list_6b = $62E1
boss_loader_list_6c = $62B5
boss_loader_list_6d = $6200
boss_loader_list_6e = $62B6
boss_loader_list_6f = $6479
boss_loader_list_70 = $622F
boss_loader_list_71 = $62F2
boss_loader_list_72 = $63D0
boss_loader_list_73 = $6497
boss_loader_list_74 = $6322
boss_loader_list_75 = $64AE
boss_loader_list_76 = $6393
boss_loader_list_77 = $64C5
boss_loader_list_78 = $63FC
boss_loader_list_79 = $64DC
boss_loader_list_7a = $62F2
boss_loader_list_7b = $6422
boss_loader_list_7c = $6455
boss_loader_list_7d = $6334
boss_loader_list_7e = $64F4
boss_loader_list_7f = $64F5

.segment "CODE"
.org $00EE
boss_loader_program_pointers:
    .word boss_loader_list_54 ; identity $54
    .word boss_loader_list_55 ; identity $55
    .word boss_loader_list_56 ; identity $56
    .word boss_loader_list_57 ; identity $57
    .word boss_loader_list_58 ; identity $58
    .word boss_loader_list_59 ; identity $59
    .word boss_loader_list_5a ; identity $5A
    .word boss_loader_list_5b ; identity $5B
    .word boss_loader_list_5c ; identity $5C
    .word boss_loader_list_5d ; identity $5D
    .word boss_loader_list_5e ; identity $5E
    .word boss_loader_list_5f ; identity $5F
    .word boss_loader_list_60 ; identity $60
    .word boss_loader_list_61 ; identity $61
    .word boss_loader_list_62 ; identity $62
    .word boss_loader_list_63 ; identity $63
    .word boss_loader_list_64 ; identity $64
    .word boss_loader_list_65 ; identity $65
    .word boss_loader_list_66 ; identity $66
    .word boss_loader_list_67 ; identity $67
    .word boss_loader_list_68 ; identity $68
    .word boss_loader_list_69 ; identity $69
    .word boss_loader_list_6a ; identity $6A
    .word boss_loader_list_6b ; identity $6B
    .word boss_loader_list_6c ; identity $6C
    .word boss_loader_list_6d ; identity $6D
    .word boss_loader_list_6e ; identity $6E
    .word boss_loader_list_6f ; identity $6F
    .word boss_loader_list_70 ; identity $70
    .word boss_loader_list_71 ; identity $71
    .word boss_loader_list_72 ; identity $72
    .word boss_loader_list_73 ; identity $73
    .word boss_loader_list_74 ; identity $74
    .word boss_loader_list_75 ; identity $75
    .word boss_loader_list_76 ; identity $76
    .word boss_loader_list_77 ; identity $77
    .word boss_loader_list_78 ; identity $78
    .word boss_loader_list_79 ; identity $79
    .word boss_loader_list_7a ; identity $7A
    .word boss_loader_list_7b ; identity $7B
    .word boss_loader_list_7c ; identity $7C
    .word boss_loader_list_7d ; identity $7D
    .word boss_loader_list_7e ; identity $7E
    .word boss_loader_list_7f ; identity $7F
