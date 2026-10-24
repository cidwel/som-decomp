; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $084E
boss_lz_controls_db084e:
    ; backreference count 5, distance 1231
    .byte $A4, $CE
    ; backreference count 3, distance 2770
    .byte $8A, $D1
    ; backreference count 5, distance 1195
    .byte $A4, $AA
    ; backreference count 3, distance 239
    .byte $80, $EE
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
