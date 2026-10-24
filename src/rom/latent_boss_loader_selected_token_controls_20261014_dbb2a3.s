; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2A3
boss_lz_controls_dbb2a3:
    ; backreference count 3, distance 95
    .byte $80, $5E
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
