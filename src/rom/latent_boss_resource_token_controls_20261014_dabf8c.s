; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF8C
boss_lz_controls_dabf8c:
    ; backreference count 3, distance 735
    .byte $82, $DE
    ; literal count 25; subsequent asset bytes excluded
    .byte $18
