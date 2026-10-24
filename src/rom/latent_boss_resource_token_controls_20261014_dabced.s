; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCED
boss_lz_controls_dabced:
    ; backreference count 4, distance 13
    .byte $84, $0C
    ; literal count 47; subsequent asset bytes excluded
    .byte $2E
