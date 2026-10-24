; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC85
boss_lz_controls_daec85:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
