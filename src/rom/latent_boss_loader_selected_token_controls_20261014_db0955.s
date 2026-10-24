; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0955
boss_lz_controls_db0955:
    ; backreference count 4, distance 2999
    .byte $9B, $B6
    ; backreference count 4, distance 545
    .byte $92, $20
    ; backreference count 4, distance 2559
    .byte $99, $FE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
