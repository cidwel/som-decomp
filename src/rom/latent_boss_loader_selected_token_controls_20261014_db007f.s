; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $007F
boss_lz_controls_db007f:
    ; backreference count 6, distance 140
    .byte $B0, $8B
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
