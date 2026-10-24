; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E562
boss_lz_controls_dae562:
    ; backreference count 18, distance 811
    .byte $FB, $2A
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 5, distance 339
    .byte $91, $52
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
