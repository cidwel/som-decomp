; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC29
boss_lz_controls_dbac29:
    ; backreference count 3, distance 1020
    .byte $83, $FB
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
