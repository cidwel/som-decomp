; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2A8
boss_lz_controls_dac2a8:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 28; subsequent asset bytes excluded
    .byte $1B
