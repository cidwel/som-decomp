; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F0EC
boss_lz_controls_daf0ec:
    ; backreference count 4, distance 2437
    .byte $99, $84
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
