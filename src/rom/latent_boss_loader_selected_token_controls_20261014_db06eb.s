; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06EB
boss_lz_controls_db06eb:
    ; backreference count 4, distance 1359
    .byte $95, $4E
    ; backreference count 3, distance 977
    .byte $83, $D0
    ; backreference count 5, distance 753
    .byte $A2, $F0
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
