; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D021
boss_lz_controls_dad021:
    ; backreference count 4, distance 156
    .byte $88, $9B
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
