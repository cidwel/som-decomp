; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B476
boss_lz_controls_dbb476:
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
