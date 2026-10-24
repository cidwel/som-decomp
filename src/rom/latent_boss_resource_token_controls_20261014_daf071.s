; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F071
boss_lz_controls_daf071:
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
