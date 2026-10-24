; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E69F
boss_lz_controls_dae69f:
    ; backreference count 3, distance 35
    .byte $80, $22
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F
