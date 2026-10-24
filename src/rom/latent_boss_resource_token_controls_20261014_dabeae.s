; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BEAE
boss_lz_controls_dabeae:
    ; backreference count 3, distance 103
    .byte $80, $66
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
