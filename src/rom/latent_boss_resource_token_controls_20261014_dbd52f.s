; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D52F
boss_lz_controls_dbd52f:
    ; backreference count 3, distance 91
    .byte $80, $5A
    ; backreference count 3, distance 115
    .byte $80, $72
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
