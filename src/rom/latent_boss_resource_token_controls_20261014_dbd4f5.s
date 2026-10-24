; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D4F5
boss_lz_controls_dbd4f5:
    ; backreference count 3, distance 34
    .byte $80, $21
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
