; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EBEB
boss_lz_controls_daebeb:
    ; backreference count 3, distance 136
    .byte $80, $87
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
