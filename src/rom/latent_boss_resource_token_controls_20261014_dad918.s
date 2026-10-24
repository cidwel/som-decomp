; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D918
boss_lz_controls_dad918:
    ; backreference count 3, distance 1408
    .byte $85, $7F
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
