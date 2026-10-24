; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA21
boss_lz_controls_daea21:
    ; backreference count 4, distance 115
    .byte $90, $72
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
