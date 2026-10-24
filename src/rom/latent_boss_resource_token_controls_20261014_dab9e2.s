; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9E2
boss_lz_controls_dab9e2:
    ; backreference count 3, distance 35
    .byte $80, $22
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
