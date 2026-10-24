; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C07D
boss_lz_controls_dac07d:
    ; backreference count 3, distance 754
    .byte $82, $F1
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
