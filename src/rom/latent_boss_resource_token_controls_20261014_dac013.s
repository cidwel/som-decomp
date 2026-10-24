; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C013
boss_lz_controls_dac013:
    ; backreference count 3, distance 756
    .byte $82, $F3
    ; literal count 28; subsequent asset bytes excluded
    .byte $1B
