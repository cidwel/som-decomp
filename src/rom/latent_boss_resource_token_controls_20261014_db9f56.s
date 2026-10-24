; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F56
boss_lz_controls_db9f56:
    ; backreference count 4, distance 22
    .byte $88, $15
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
