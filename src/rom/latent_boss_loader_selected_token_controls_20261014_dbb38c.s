; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B38C
boss_lz_controls_dbb38c:
    ; backreference count 3, distance 50
    .byte $80, $31
    ; literal count 37; subsequent asset bytes excluded
    .byte $24
