; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCC8
boss_lz_controls_dabcc8:
    ; backreference count 3, distance 34
    .byte $80, $21
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
