; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D80F
boss_lz_controls_dbd80f:
    ; backreference count 3, distance 18
    .byte $80, $11
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
