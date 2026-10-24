; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B320
boss_lz_controls_dbb320:
    ; literal count 98; subsequent asset bytes excluded
    .byte $61
