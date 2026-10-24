; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE9C
boss_lz_controls_dade9c:
    ; backreference count 5, distance 192
    .byte $90, $BF
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
