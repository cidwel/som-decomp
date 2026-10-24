; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D314
boss_lz_controls_dbd314:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
