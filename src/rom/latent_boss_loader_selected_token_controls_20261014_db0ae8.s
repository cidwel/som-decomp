; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AE8
boss_lz_controls_db0ae8:
    ; backreference count 4, distance 3520
    .byte $9D, $BF
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
