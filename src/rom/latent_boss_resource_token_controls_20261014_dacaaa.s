; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAAA
boss_lz_controls_dacaaa:
    ; backreference count 3, distance 1320
    .byte $85, $27
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
