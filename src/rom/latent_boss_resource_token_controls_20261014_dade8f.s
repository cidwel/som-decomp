; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE8F
boss_lz_controls_dade8f:
    ; backreference count 4, distance 190
    .byte $88, $BD
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
