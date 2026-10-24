; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E16D
boss_lz_controls_dae16d:
    ; backreference count 3, distance 110
    .byte $80, $6D
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
