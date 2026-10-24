; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01E9
boss_lz_controls_db01e9:
    ; backreference count 3, distance 8
    .byte $80, $07
    ; backreference count 10, distance 9
    .byte $F0, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
