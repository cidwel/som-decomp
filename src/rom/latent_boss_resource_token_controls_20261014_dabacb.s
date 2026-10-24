; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BACB
boss_lz_controls_dabacb:
    ; backreference count 10, distance 265
    .byte $9D, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
