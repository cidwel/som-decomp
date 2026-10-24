; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2CA
boss_lz_controls_dbb2ca:
    ; backreference count 3, distance 129
    .byte $80, $80
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
