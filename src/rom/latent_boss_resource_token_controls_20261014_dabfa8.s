; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFA8
boss_lz_controls_dabfa8:
    ; backreference count 3, distance 768
    .byte $82, $FF
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
