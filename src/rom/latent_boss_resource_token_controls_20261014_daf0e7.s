; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F0E7
boss_lz_controls_daf0e7:
    ; backreference count 3, distance 3039
    .byte $8B, $DE
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
