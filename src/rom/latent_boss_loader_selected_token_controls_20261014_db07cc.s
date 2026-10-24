; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07CC
boss_lz_controls_db07cc:
    ; backreference count 6, distance 38
    .byte $B0, $25
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
