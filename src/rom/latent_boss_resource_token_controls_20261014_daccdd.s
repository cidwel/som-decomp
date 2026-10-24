; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCDD
boss_lz_controls_daccdd:
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
