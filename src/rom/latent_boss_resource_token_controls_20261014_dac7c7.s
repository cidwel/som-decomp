; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C7C7
boss_lz_controls_dac7c7:
    ; backreference count 3, distance 760
    .byte $82, $F7
    ; literal count 28; subsequent asset bytes excluded
    .byte $1B
