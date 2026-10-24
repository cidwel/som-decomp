; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09E8
boss_lz_controls_db09e8:
    ; backreference count 4, distance 1423
    .byte $95, $8E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
