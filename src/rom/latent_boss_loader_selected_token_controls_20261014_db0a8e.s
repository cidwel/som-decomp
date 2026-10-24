; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A8E
boss_lz_controls_db0a8e:
    ; backreference count 3, distance 7
    .byte $80, $06
    ; backreference count 5, distance 14
    .byte $A0, $0D
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
