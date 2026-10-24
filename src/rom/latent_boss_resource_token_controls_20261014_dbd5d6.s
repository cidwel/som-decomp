; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D5D6
boss_lz_controls_dbd5d6:
    ; backreference count 4, distance 730
    .byte $86, $D9
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
