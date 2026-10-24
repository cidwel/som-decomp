; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C641
boss_lz_controls_dac641:
    ; backreference count 3, distance 92
    .byte $80, $5B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
