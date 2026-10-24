; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $929D
boss_lz_controls_db929d:
    ; backreference count 3, distance 207
    .byte $80, $CE
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
