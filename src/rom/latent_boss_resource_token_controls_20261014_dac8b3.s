; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8B3
boss_lz_controls_dac8b3:
    ; backreference count 3, distance 1072
    .byte $84, $2F
    ; literal count 25; subsequent asset bytes excluded
    .byte $18
