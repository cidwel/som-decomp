; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D1F6
boss_lz_controls_dbd1f6:
    ; backreference count 3, distance 1716
    .byte $86, $B3
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
