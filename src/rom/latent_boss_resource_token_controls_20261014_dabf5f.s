; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF5F
boss_lz_controls_dabf5f:
    ; backreference count 3, distance 318
    .byte $81, $3D
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
