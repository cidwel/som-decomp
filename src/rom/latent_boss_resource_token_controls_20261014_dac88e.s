; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C88E
boss_lz_controls_dac88e:
    ; backreference count 3, distance 286
    .byte $81, $1D
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
