; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BDAD
boss_lz_controls_dbbdad:
    ; backreference count 3, distance 277
    .byte $81, $14
    ; literal count 39; subsequent asset bytes excluded
    .byte $26
