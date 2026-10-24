; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EDEE
boss_lz_controls_daedee:
    ; backreference count 3, distance 1195
    .byte $84, $AA
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
