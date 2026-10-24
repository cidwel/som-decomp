; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EE03
boss_lz_controls_daee03:
    ; backreference count 6, distance 116
    .byte $B0, $73
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
