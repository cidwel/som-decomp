; Typed map structure; docs/map-structural-index-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7000
map_header_object_list_pointers:
    ; Map IDs $000..$007; bank C8 is supplied by the consumer.
    .word $9000, $9000, $9000, $9000, $9000, $9000, $9000, $9000
    ; Map IDs $008..$00F; bank C8 is supplied by the consumer.
    .word $9000, $9008, $9008, $9008, $9008, $9008, $9008, $9010
    ; Map IDs $010..$017; bank C8 is supplied by the consumer.
    .word $9060, $9118, $91F0, $9208, $9238, $9338, $9388, $9390
    ; Map IDs $018..$01F; bank C8 is supplied by the consumer.
    .word $9460, $9480, $9530, $9540, $9578, $95D8, $9628, $9668
    ; Map IDs $020..$027; bank C8 is supplied by the consumer.
    .word $96A8, $96C0, $96D0, $96E0, $9700, $9750, $9790, $97B0
    ; Map IDs $028..$02F; bank C8 is supplied by the consumer.
    .word $9820, $98A0, $9928, $9A88, $9C00, $9C88, $9D10, $9D38
    ; Map IDs $030..$037; bank C8 is supplied by the consumer.
    .word $9D40, $9D60, $9DC0, $9DC0, $9E28, $9E98, $9F00, $9F60
    ; Map IDs $038..$03F; bank C8 is supplied by the consumer.
    .word $9FA0, $9FC0, $A010, $A030, $A080, $A090, $A100, $A1A0
    ; Map IDs $040..$047; bank C8 is supplied by the consumer.
    .word $A1E0, $A220, $A260, $A268, $A2A0, $A2E0, $A320, $A350
    ; Map IDs $048..$04F; bank C8 is supplied by the consumer.
    .word $A378, $A398, $A3A8, $A3A8, $A3C0, $A448, $A4D8, $A4E8
    ; Map IDs $050..$057; bank C8 is supplied by the consumer.
    .word $A4F8, $A570, $A600, $A650, $A670, $A678, $A6B0, $A6E8
    ; Map IDs $058..$05F; bank C8 is supplied by the consumer.
    .word $A720, $A758, $A7A8, $A7E8, $A820, $A860, $A898, $A8D0
    ; Map IDs $060..$067; bank C8 is supplied by the consumer.
    .word $A900, $A938, $A968, $A9B0, $A9F8, $AA10, $AA20, $AA48
    ; Map IDs $068..$06F; bank C8 is supplied by the consumer.
    .word $AA58, $AA88, $AAD8, $AAE0, $AAF0, $AB30, $AB50, $AB60
    ; Map IDs $070..$077; bank C8 is supplied by the consumer.
    .word $AB70, $AB78, $ABC0, $AC10, $AC60, $AC68, $ACB0, $ACE0
    ; Map IDs $078..$07F; bank C8 is supplied by the consumer.
    .word $ACF0, $AD10, $AD28, $AD70, $ADD0, $ADE0, $AE38, $AE78
    ; Map IDs $080..$087; bank C8 is supplied by the consumer.
    .word $AE90, $AEB0, $AF10, $AF68, $AFC0, $AFC8, $B018, $B030
    ; Map IDs $088..$08F; bank C8 is supplied by the consumer.
    .word $B040, $B088, $B098, $B0C8, $B108, $B128, $B128, $B170
    ; Map IDs $090..$097; bank C8 is supplied by the consumer.
    .word $B190, $B1D8, $B1E0, $B210, $B228, $B250, $B288, $B2B0
    ; Map IDs $098..$09F; bank C8 is supplied by the consumer.
    .word $B2D0, $B2E0, $B2F0, $B2F0, $B340, $B390, $B3E0, $B430
    ; Map IDs $0A0..$0A7; bank C8 is supplied by the consumer.
    .word $B480, $B4D0, $B500, $B550, $B5A8, $B600, $B668, $B678
    ; Map IDs $0A8..$0AF; bank C8 is supplied by the consumer.
    .word $B6B0, $B6D0, $B6D0, $B6D8, $B728, $B728, $B728, $B728
    ; Map IDs $0B0..$0B7; bank C8 is supplied by the consumer.
    .word $B728, $B730, $B738, $B740, $B748, $B750, $B750, $B750
    ; Map IDs $0B8..$0BF; bank C8 is supplied by the consumer.
    .word $B750, $B750, $B750, $B750, $B750, $B750, $B750, $B750
    ; Map IDs $0C0..$0C7; bank C8 is supplied by the consumer.
    .word $B750, $B750, $B750, $B7A0, $B8D8, $B928, $B950, $B968
    ; Map IDs $0C8..$0CF; bank C8 is supplied by the consumer.
    .word $B988, $B9A0, $B9C0, $B9E0, $BA68, $BA78, $BAA0, $BAC0
    ; Map IDs $0D0..$0D7; bank C8 is supplied by the consumer.
    .word $BAE8, $BB08, $BB30, $BB50, $BB70, $BBA0, $BBB0, $BBD0
    ; Map IDs $0D8..$0DF; bank C8 is supplied by the consumer.
    .word $BBF0, $BC10, $BC38, $BC60, $BC88, $BCB8, $BCE0, $BD38
    ; Map IDs $0E0..$0E7; bank C8 is supplied by the consumer.
    .word $BD80, $BDA8, $BDD8, $BDE8, $BE20, $BE50, $BE78, $BE88
    ; Map IDs $0E8..$0EF; bank C8 is supplied by the consumer.
    .word $BE98, $BEA8, $BEB0, $BEB8, $BEC0, $BEF0, $BF00, $BF10
    ; Map IDs $0F0..$0F7; bank C8 is supplied by the consumer.
    .word $BF10, $BF20, $BF28, $BF28, $BF28, $BF38, $BF58, $BF78
    ; Map IDs $0F8..$0FF; bank C8 is supplied by the consumer.
    .word $BF78, $C0B8, $C208, $C360, $C368, $C368, $C378, $C378
    ; Map IDs $100..$107; bank C8 is supplied by the consumer.
    .word $C3B0, $C3D0, $C410, $C450, $C460, $C470, $C4D0, $C4E0
    ; Map IDs $108..$10F; bank C8 is supplied by the consumer.
    .word $C508, $C548, $C588, $C5D0, $C5F0, $C628, $C658, $C678
    ; Map IDs $110..$117; bank C8 is supplied by the consumer.
    .word $C6C0, $C6C0, $C6E8, $C6F8, $C718, $C738, $C748, $C758
    ; Map IDs $118..$11F; bank C8 is supplied by the consumer.
    .word $C768, $C798, $C7A8, $C7B8, $C7E8, $C830, $C898, $C8E8
    ; Map IDs $120..$127; bank C8 is supplied by the consumer.
    .word $C928, $C930, $C950, $C970, $C980, $C990, $C9A0, $C9B0
    ; Map IDs $128..$12F; bank C8 is supplied by the consumer.
    .word $C9B8, $C9D8, $CA08, $CA28, $CA38, $CA48, $CA68, $CA80
    ; Map IDs $130..$137; bank C8 is supplied by the consumer.
    .word $CAA0, $CAB8, $CAC8, $CB08, $CB28, $CB58, $CB70, $CB80
    ; Map IDs $138..$13F; bank C8 is supplied by the consumer.
    .word $CB88, $CBD8, $CC08, $CC18, $CC28, $CC68, $CC78, $CC80
    ; Map IDs $140..$147; bank C8 is supplied by the consumer.
    .word $CCA0, $CCC8, $CD20, $CD58, $CDB0, $CDC8, $CDD8, $CDF0
    ; Map IDs $148..$14F; bank C8 is supplied by the consumer.
    .word $CE10, $CE30, $CE48, $CEA0, $CEC8, $CEE0, $CEF8, $CEF8
    ; Map IDs $150..$157; bank C8 is supplied by the consumer.
    .word $CF30, $CF60, $CFA0, $CFB0, $CFE8, $CFF8, $D008, $D030
    ; Map IDs $158..$15F; bank C8 is supplied by the consumer.
    .word $D050, $D070, $D0A8, $D0F8, $D108, $D128, $D140, $D148
    ; Map IDs $160..$167; bank C8 is supplied by the consumer.
    .word $D168, $D188, $D198, $D1B8, $D1E0, $D200, $D228, $D238
    ; Map IDs $168..$16F; bank C8 is supplied by the consumer.
    .word $D278, $D298, $D2B8, $D2E8, $D300, $D310, $D330, $D330
    ; Map IDs $170..$177; bank C8 is supplied by the consumer.
    .word $D340, $D398, $D3D0, $D400, $D420, $D438, $D458, $D4B8
    ; Map IDs $178..$17F; bank C8 is supplied by the consumer.
    .word $D4D8, $D4E8, $D4F8, $D518, $D538, $D568, $D580, $D5A0
    ; Map IDs $180..$187; bank C8 is supplied by the consumer.
    .word $D5D0, $D600, $D640, $D660, $D680, $D690, $D6C8, $D6E8
    ; Map IDs $188..$18F; bank C8 is supplied by the consumer.
    .word $D710, $D710, $D718, $D720, $D728, $D730, $D730, $D730
    ; Map IDs $190..$197; bank C8 is supplied by the consumer.
    .word $D730, $D790, $D840, $D870, $D940, $D990, $D9B0, $DA48
    ; Map IDs $198..$19F; bank C8 is supplied by the consumer.
    .word $DA58, $DA78, $DAB0, $DAB8, $DAB8, $DAF8, $DB38, $DBA0
    ; Map IDs $1A0..$1A7; bank C8 is supplied by the consumer.
    .word $DC10, $DC78, $DCF0, $DD10, $DD18, $DD40, $DD68, $DD90
    ; Map IDs $1A8..$1AF; bank C8 is supplied by the consumer.
    .word $DDB8, $DDE0, $DE08, $DE30, $DE30, $DE38, $DE38, $DE78
    ; Map IDs $1B0..$1B7; bank C8 is supplied by the consumer.
    .word $DEA0, $DEC0, $DF70, $DF98, $DFA0, $DFC0, $DFC0, $DFC0
    ; Map IDs $1B8..$1BF; bank C8 is supplied by the consumer.
    .word $DFC0, $DFC0, $DFC0, $DFC0, $DFC0, $DFC8, $DFD0, $DFD8
    ; Map IDs $1C0..$1C7; bank C8 is supplied by the consumer.
    .word $DFD8, $E028, $E038, $E038, $E038, $E038, $E038, $E038
    ; Map IDs $1C8..$1CF; bank C8 is supplied by the consumer.
    .word $E038, $E038, $E038, $E038, $E038, $E038, $E038, $E038
    ; Map IDs $1D0..$1D7; bank C8 is supplied by the consumer.
    .word $E038, $E038, $E038, $E038, $E038, $E038, $E038, $E038
    ; Map IDs $1D8..$1DF; bank C8 is supplied by the consumer.
    .word $E038, $E038, $E038, $E038, $E038, $E038, $E038, $E038
    ; Map IDs $1E0..$1E7; bank C8 is supplied by the consumer.
    .word $E038, $E038, $E038, $E038, $E038, $E038, $E038, $E038
    ; Map IDs $1E8..$1EF; bank C8 is supplied by the consumer.
    .word $E038, $E048, $E058, $E058, $E058, $E058, $E058, $E058
    ; Map IDs $1F0..$1F7; bank C8 is supplied by the consumer.
    .word $E068, $E068, $E068, $E068, $E068, $E068, $E068, $E068
    ; Map IDs $1F8..$1FF; bank C8 is supplied by the consumer.
    .word $E068, $E068, $E068, $E068, $E068, $E068, $E068, $E068
