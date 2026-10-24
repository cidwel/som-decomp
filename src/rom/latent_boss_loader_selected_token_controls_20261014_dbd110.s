; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D110
boss_lz_controls_dbd110:
    ; backreference count 4, distance 2350
    .byte $99, $2D
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
