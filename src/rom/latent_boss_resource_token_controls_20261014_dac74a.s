; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C74A
boss_lz_controls_dac74a:
    ; backreference count 3, distance 48
    .byte $80, $2F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
