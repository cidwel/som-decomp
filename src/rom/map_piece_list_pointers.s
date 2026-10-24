; Typed map structure; docs/map-structural-index-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5000
map_piece_list_pointers:
    ; Map IDs $000..$007; bank C8 is supplied by the consumer.
    .word $5402, $540E, $541A, $5426, $5426, $5432, $543E, $543E
    ; Map IDs $008..$00F; bank C8 is supplied by the consumer.
    .word $5444, $5450, $5450, $5450, $5450, $5450, $5450, $545C
    ; Map IDs $010..$017; bank C8 is supplied by the consumer.
    .word $5468, $5474, $5480, $549B, $54A7, $5530, $553C, $5548
    ; Map IDs $018..$01F; bank C8 is supplied by the consumer.
    .word $5554, $5560, $556C, $5578, $5584, $5590, $55A1, $55BC
    ; Map IDs $020..$027; bank C8 is supplied by the consumer.
    .word $55C8, $55E8, $55F9, $560A, $5616, $5622, $562E, $563A
    ; Map IDs $028..$02F; bank C8 is supplied by the consumer.
    .word $566E, $5698, $56D6, $5705, $572F, $573B, $5747, $5753
    ; Map IDs $030..$037; bank C8 is supplied by the consumer.
    .word $575F, $576B, $57A4, $57A4, $57B0, $57F8, $583B, $5865
    ; Map IDs $038..$03F; bank C8 is supplied by the consumer.
    .word $589E, $58AA, $58B6, $58C2, $58CE, $58EE, $58FA, $591F
    ; Map IDs $040..$047; bank C8 is supplied by the consumer.
    .word $592B, $594B, $5957, $5963, $599C, $59EE, $5A31, $5A65
    ; Map IDs $048..$04F; bank C8 is supplied by the consumer.
    .word $5A7B, $5A87, $5A98, $5A98, $5AA4, $5AE2, $5B0C, $5B18
    ; Map IDs $050..$057; bank C8 is supplied by the consumer.
    .word $5B24, $5B30, $5B64, $5B7A, $5B90, $5BCE, $5C16, $5C54
    ; Map IDs $058..$05F; bank C8 is supplied by the consumer.
    .word $5CA1, $5CDF, $5CF5, $5D01, $5D49, $5D82, $5DC0, $5DFE
    ; Map IDs $060..$067; bank C8 is supplied by the consumer.
    .word $5E41, $5E75, $5EBD, $5EC9, $5ED5, $5EE6, $5F01, $5F12
    ; Map IDs $068..$06F; bank C8 is supplied by the consumer.
    .word $5F64, $5F70, $5F7C, $5FC4, $5FD0, $5FDC, $5FE8, $5FF4
    ; Map IDs $070..$077; bank C8 is supplied by the consumer.
    .word $602D, $6039, $6054, $607E, $60B2, $60BE, $612E, $61AD
    ; Map IDs $078..$07F; bank C8 is supplied by the consumer.
    .word $61E6, $61F2, $61FE, $622D, $626B, $62A9, $62E2, $6311
    ; Map IDs $080..$087; bank C8 is supplied by the consumer.
    .word $634F, $636A, $6385, $6391, $63A2, $63AE, $63BA, $63C6
    ; Map IDs $088..$08F; bank C8 is supplied by the consumer.
    .word $63D7, $6429, $645D, $649B, $653D, $6571, $6571, $6613
    ; Map IDs $090..$097; bank C8 is supplied by the consumer.
    .word $66B5, $66C1, $66CD, $66F7, $6703, $6737, $6743, $6768
    ; Map IDs $098..$09F; bank C8 is supplied by the consumer.
    .word $6774, $6780, $678C, $678C, $6798, $67A4, $67B0, $67BC
    ; Map IDs $0A0..$0A7; bank C8 is supplied by the consumer.
    .word $67C8, $67D4, $67E0, $684B, $68BB, $6926, $6991, $6997
    ; Map IDs $0A8..$0AF; bank C8 is supplied by the consumer.
    .word $6A02, $6A0E, $6A0E, $6A1A, $6A26, $6A26, $6A26, $6A26
    ; Map IDs $0B0..$0B7; bank C8 is supplied by the consumer.
    .word $6A26, $6A50, $6A66, $6A72, $6A83, $6A8F, $6A8F, $6A8F
    ; Map IDs $0B8..$0BF; bank C8 is supplied by the consumer.
    .word $6A8F, $6A8F, $6A8F, $6A8F, $6A8F, $6A8F, $6A8F, $6A8F
    ; Map IDs $0C0..$0C7; bank C8 is supplied by the consumer.
    .word $6A8F, $6A8F, $6A8F, $6A9B, $6B8D, $6B99, $6BA5, $6C15
    ; Map IDs $0C8..$0CF; bank C8 is supplied by the consumer.
    .word $6C2B, $6C37, $6C4D, $6C5E, $6C6A, $6C76, $6C82, $6C98
    ; Map IDs $0D0..$0D7; bank C8 is supplied by the consumer.
    .word $6CB3, $6CBF, $6CCB, $6CDC, $6CED, $6CF9, $6D0A, $6D20
    ; Map IDs $0D8..$0DF; bank C8 is supplied by the consumer.
    .word $6D2C, $6D47, $6D53, $6D64, $6D70, $6D90, $6D9C, $6DC6
    ; Map IDs $0E0..$0E7; bank C8 is supplied by the consumer.
    .word $6DE6, $6E10, $6E2B, $6E3C, $6E48, $6E54, $6E65, $6E6B
    ; Map IDs $0E8..$0EF; bank C8 is supplied by the consumer.
    .word $6E71, $6E77, $6E83, $6E8F, $6E9B, $6EB1, $6ECC, $6ED2
    ; Map IDs $0F0..$0F7; bank C8 is supplied by the consumer.
    .word $6ED2, $6FA1, $6FAD, $6FAD, $7408, $74C8, $74D9, $74E4
    ; Map IDs $0F8..$0FF; bank C8 is supplied by the consumer.
    .word $74E4, $75EA, $76C8, $76D4, $76E0, $76E0, $76E6, $76E6
    ; Map IDs $100..$107; bank C8 is supplied by the consumer.
    .word $7710, $7799, $77A5, $77B1, $77BD, $77C9, $77D5, $77E1
    ; Map IDs $108..$10F; bank C8 is supplied by the consumer.
    .word $77ED, $77F9, $780A, $7820, $782C, $7838, $786C, $7878
    ; Map IDs $110..$117; bank C8 is supplied by the consumer.
    .word $7884, $7884, $7890, $789C, $78B2, $78BE, $78D4, $78E0
    ; Map IDs $118..$11F; bank C8 is supplied by the consumer.
    .word $78EC, $78F8, $7904, $7910, $7921, $7932, $795C, $797C
    ; Map IDs $120..$127; bank C8 is supplied by the consumer.
    .word $799C, $79A8, $79B4, $79C5, $79DB, $79E7, $79F3, $7A04
    ; Map IDs $128..$12F; bank C8 is supplied by the consumer.
    .word $7A2E, $7A3A, $7A46, $7A52, $7A5E, $7A7E, $7A99, $7AB9
    ; Map IDs $130..$137; bank C8 is supplied by the consumer.
    .word $7ACA, $7AD6, $7B00, $7B0C, $7B18, $7B4C, $7B67, $7B78
    ; Map IDs $138..$13F; bank C8 is supplied by the consumer.
    .word $7B84, $7C62, $7CDC, $7D29, $7D35, $7D4B, $7D65, $7D71
    ; Map IDs $140..$147; bank C8 is supplied by the consumer.
    .word $7D7D, $7D89, $7D9A, $7DA6, $7DB2, $7DBE, $7DDE, $7DEA
    ; Map IDs $148..$14F; bank C8 is supplied by the consumer.
    .word $7E05, $7E11, $7E1D, $7E29, $7E35, $7E41, $7E4D, $7E4D
    ; Map IDs $150..$157; bank C8 is supplied by the consumer.
    .word $7E63, $7E6F, $7E7B, $7E87, $7E93, $7E9F, $7EAB, $7EB7
    ; Map IDs $158..$15F; bank C8 is supplied by the consumer.
    .word $7ECD, $7ED9, $7EEA, $7EF6, $7F0C, $7F22, $7F2E, $7F3A
    ; Map IDs $160..$167; bank C8 is supplied by the consumer.
    .word $7F46, $7F66, $7F86, $7F92, $7FBC, $7FC8, $7FFC, $8008
    ; Map IDs $168..$16F; bank C8 is supplied by the consumer.
    .word $8014, $8048, $8054, $8060, $806C, $8078, $809D, $809D
    ; Map IDs $170..$177; bank C8 is supplied by the consumer.
    .word $80B3, $80CE, $80DA, $80F5, $8101, $810D, $8119, $8143
    ; Map IDs $178..$17F; bank C8 is supplied by the consumer.
    .word $814F, $815B, $816C, $8178, $8184, $819A, $81A6, $81C6
    ; Map IDs $180..$187; bank C8 is supplied by the consumer.
    .word $81D2, $81DE, $81EA, $8200, $820C, $822C, $8238, $8244
    ; Map IDs $188..$18F; bank C8 is supplied by the consumer.
    .word $8250, $8250, $8266, $8272, $827E, $828A, $828A, $8296
    ; Map IDs $190..$197; bank C8 is supplied by the consumer.
    .word $8296, $82B6, $8330, $8396, $8429, $8494, $84FA, $8524
    ; Map IDs $198..$19F; bank C8 is supplied by the consumer.
    .word $852A, $8536, $85A1, $85AD, $85AD, $85C3, $85E3, $8617
    ; Map IDs $1A0..$1A7; bank C8 is supplied by the consumer.
    .word $8650, $8666, $86B8, $86F1, $8707, $8718, $8729, $873A
    ; Map IDs $1A8..$1AF; bank C8 is supplied by the consumer.
    .word $874B, $875C, $876D, $877E, $877E, $878A, $878A, $87BE
    ; Map IDs $1B0..$1B7; bank C8 is supplied by the consumer.
    .word $87D4, $87E0, $8800, $8816, $882C, $8838, $8838, $8838
    ; Map IDs $1B8..$1BF; bank C8 is supplied by the consumer.
    .word $8838, $8838, $8838, $8838, $8838, $8844, $8850, $885C
    ; Map IDs $1C0..$1C7; bank C8 is supplied by the consumer.
    .word $885C, $8868, $8874, $8874, $8874, $8874, $8874, $8874
    ; Map IDs $1C8..$1CF; bank C8 is supplied by the consumer.
    .word $8874, $8874, $8874, $8874, $8874, $8874, $8874, $8874
    ; Map IDs $1D0..$1D7; bank C8 is supplied by the consumer.
    .word $8874, $8874, $8874, $8874, $8874, $8874, $8874, $8874
    ; Map IDs $1D8..$1DF; bank C8 is supplied by the consumer.
    .word $8874, $8874, $8874, $8874, $8874, $8874, $8874, $8874
    ; Map IDs $1E0..$1E7; bank C8 is supplied by the consumer.
    .word $8874, $8874, $8874, $8880, $8880, $888C, $8898, $88A4
    ; Map IDs $1E8..$1EF; bank C8 is supplied by the consumer.
    .word $88B0, $88BC, $88C8, $88C8, $88C8, $88C8, $88C8, $88C8
    ; Map IDs $1F0..$1F7; bank C8 is supplied by the consumer.
    .word $88F7, $88F7, $88F7, $88F7, $88F7, $88F7, $88F7, $88F7
    ; Map IDs $1F8..$1FF; bank C8 is supplied by the consumer.
    .word $88F7, $88F7, $88F7, $88F7, $88F7, $88F7, $88F7, $88F7
