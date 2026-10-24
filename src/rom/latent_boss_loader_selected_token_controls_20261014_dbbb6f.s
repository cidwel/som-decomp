; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB6F
boss_lz_controls_dbbb6f:
    ; backreference count 3, distance 434
    .byte $81, $B1
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
