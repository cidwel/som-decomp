; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D633
boss_lz_controls_dbd633:
    ; backreference count 3, distance 104
    .byte $80, $67
    ; backreference count 4, distance 177
    .byte $84, $B0
    ; literal count 29; subsequent asset bytes excluded
    .byte $1C
