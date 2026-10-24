; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C96A
boss_lz_controls_dac96a:
    ; backreference count 8, distance 1178
    .byte $AC, $99
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
