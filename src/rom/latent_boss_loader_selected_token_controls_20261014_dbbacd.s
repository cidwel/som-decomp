; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BACD
boss_lz_controls_dbbacd:
    ; backreference count 3, distance 244
    .byte $80, $F3
    ; backreference count 3, distance 341
    .byte $81, $54
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
