; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0E7
boss_lz_controls_dbb0e7:
    ; backreference count 3, distance 207
    .byte $80, $CE
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
