; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08FC
boss_lz_controls_db08fc:
    ; backreference count 6, distance 3079
    .byte $BC, $06
    ; backreference count 7, distance 1378
    .byte $C5, $61
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
