; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B5F8
boss_lz_controls_dbb5f8:
    ; backreference count 3, distance 31
    .byte $80, $1E
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
