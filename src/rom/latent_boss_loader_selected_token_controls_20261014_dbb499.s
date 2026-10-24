; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B499
boss_lz_controls_dbb499:
    ; backreference count 3, distance 75
    .byte $80, $4A
    ; literal count 69; subsequent asset bytes excluded
    .byte $44
