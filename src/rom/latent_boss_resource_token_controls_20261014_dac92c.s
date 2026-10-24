; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C92C
boss_lz_controls_dac92c:
    ; backreference count 3, distance 1234
    .byte $84, $D1
    ; literal count 33; subsequent asset bytes excluded
    .byte $20
