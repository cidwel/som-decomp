; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7E6
boss_lz_controls_dbd7e6:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
