; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0C59
boss_lz_controls_db0c59:
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
