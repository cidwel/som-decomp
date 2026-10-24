; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0995
boss_lz_controls_db0995:
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
