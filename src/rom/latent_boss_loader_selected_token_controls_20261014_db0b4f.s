; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B4F
boss_lz_controls_db0b4f:
    ; backreference count 10, distance 193
    .byte $F0, $C0
    ; backreference count 9, distance 193
    .byte $E0, $C0
    ; backreference count 6, distance 14
    .byte $B0, $0D
    ; backreference count 5, distance 26
    .byte $A0, $19
    ; backreference count 5, distance 256
    .byte $A0, $FF
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
