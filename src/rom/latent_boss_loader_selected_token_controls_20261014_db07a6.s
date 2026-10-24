; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07A6
boss_lz_controls_db07a6:
    ; backreference count 4, distance 2785
    .byte $9A, $E0
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
