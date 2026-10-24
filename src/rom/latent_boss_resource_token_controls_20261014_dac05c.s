; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C05C
boss_lz_controls_dac05c:
    ; backreference count 5, distance 758
    .byte $8A, $F5
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
