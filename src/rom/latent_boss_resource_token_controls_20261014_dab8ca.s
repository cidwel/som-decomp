; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8CA
boss_lz_controls_dab8ca:
    ; backreference count 4, distance 483
    .byte $85, $E2
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
