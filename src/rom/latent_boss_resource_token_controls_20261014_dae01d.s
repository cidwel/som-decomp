; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E01D
boss_lz_controls_dae01d:
    ; backreference count 3, distance 80
    .byte $80, $4F
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
