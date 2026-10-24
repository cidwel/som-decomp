; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBDA
boss_lz_controls_dabbda:
    ; backreference count 3, distance 445
    .byte $81, $BC
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
