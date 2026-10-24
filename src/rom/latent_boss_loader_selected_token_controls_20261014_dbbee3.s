; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BEE3
boss_lz_controls_dbbee3:
    ; backreference count 6, distance 550
    .byte $9A, $25
    ; literal count 80; subsequent asset bytes excluded
    .byte $4F
