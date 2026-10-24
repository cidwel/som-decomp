; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D5E2
boss_lz_controls_dbd5e2:
    ; backreference count 4, distance 754
    .byte $86, $F1
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
