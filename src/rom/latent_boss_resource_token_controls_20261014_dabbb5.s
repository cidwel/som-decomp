; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBB5
boss_lz_controls_dabbb5:
    ; backreference count 3, distance 160
    .byte $80, $9F
    ; backreference count 3, distance 34
    .byte $80, $21
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
