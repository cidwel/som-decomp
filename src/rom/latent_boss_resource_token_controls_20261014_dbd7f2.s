; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7F2
boss_lz_controls_dbd7f2:
    ; backreference count 3, distance 223
    .byte $80, $DE
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
