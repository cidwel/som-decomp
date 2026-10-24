; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B715
boss_lz_controls_dbb715:
    ; backreference count 3, distance 76
    .byte $80, $4B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
