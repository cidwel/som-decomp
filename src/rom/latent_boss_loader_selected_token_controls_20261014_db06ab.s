; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06AB
boss_lz_controls_db06ab:
    ; backreference count 9, distance 789
    .byte $E3, $14
    ; backreference count 6, distance 95
    .byte $B0, $5E
    ; backreference count 5, distance 807
    .byte $A3, $26
    ; backreference count 6, distance 8
    .byte $B0, $07
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
