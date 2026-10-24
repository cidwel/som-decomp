; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0AA
boss_lz_controls_dbd0aa:
    ; backreference count 4, distance 1522
    .byte $95, $F1
    ; literal count 64; subsequent asset bytes excluded
    .byte $3F
