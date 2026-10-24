; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BE6
boss_lz_controls_db0be6:
    ; big-endian decoded byte count
    .byte $05, $00
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
