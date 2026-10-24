; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E078
boss_lz_controls_dae078:
    ; backreference count 4, distance 1231
    .byte $8C, $CE
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
