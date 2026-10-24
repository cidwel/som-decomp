; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E7D8
boss_lz_controls_dae7d8:
    ; backreference count 3, distance 130
    .byte $80, $81
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
