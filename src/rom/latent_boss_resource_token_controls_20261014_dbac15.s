; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC15
boss_lz_controls_dbac15:
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
