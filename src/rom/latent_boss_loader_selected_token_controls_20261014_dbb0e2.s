; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0E2
boss_lz_controls_dbb0e2:
    ; backreference count 16, distance 207
    .byte $B4, $CE
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
