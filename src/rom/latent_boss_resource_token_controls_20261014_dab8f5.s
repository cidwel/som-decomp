; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8F5
boss_lz_controls_dab8f5:
    ; backreference count 3, distance 224
    .byte $80, $DF
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
