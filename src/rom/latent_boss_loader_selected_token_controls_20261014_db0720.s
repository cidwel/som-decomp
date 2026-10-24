; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0720
boss_lz_controls_db0720:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; backreference count 8, distance 19
    .byte $D0, $12
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
