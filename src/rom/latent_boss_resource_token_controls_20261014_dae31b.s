; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E31B
boss_lz_controls_dae31b:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
