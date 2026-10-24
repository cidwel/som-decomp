; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAFF
boss_lz_controls_dabaff:
    ; backreference count 10, distance 33
    .byte $9C, $20
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
