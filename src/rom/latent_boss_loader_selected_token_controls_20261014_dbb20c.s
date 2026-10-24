; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B20C
boss_lz_controls_dbb20c:
    ; backreference count 14, distance 14
    .byte $AC, $0D
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
