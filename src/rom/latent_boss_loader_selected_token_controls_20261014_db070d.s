; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $070D
boss_lz_controls_db070d:
    ; backreference count 4, distance 1231
    .byte $94, $CE
    ; backreference count 3, distance 22
    .byte $80, $15
    ; backreference count 6, distance 1044
    .byte $B4, $13
    ; backreference count 3, distance 118
    .byte $80, $75
    ; backreference count 5, distance 2193
    .byte $A8, $90
    ; backreference count 8, distance 1433
    .byte $D5, $98
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
