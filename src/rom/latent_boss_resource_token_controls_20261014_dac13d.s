; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C13D
boss_lz_controls_dac13d:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
