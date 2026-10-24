; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA69
boss_lz_controls_daea69:
    ; backreference count 6, distance 185
    .byte $B0, $B8
    ; backreference count 6, distance 70
    .byte $B0, $45
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
