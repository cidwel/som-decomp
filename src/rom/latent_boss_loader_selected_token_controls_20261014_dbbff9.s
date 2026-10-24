; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFF9
boss_lz_controls_dbbff9:
    ; backreference count 3, distance 758
    .byte $82, $F5
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
