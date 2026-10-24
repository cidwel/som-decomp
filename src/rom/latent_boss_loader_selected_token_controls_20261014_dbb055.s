; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B055
boss_lz_controls_dbb055:
    ; backreference count 3, distance 247
    .byte $80, $F6
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
