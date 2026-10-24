; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B0E
boss_lz_controls_db0b0e:
    ; backreference count 7, distance 163
    .byte $C0, $A2
    ; backreference count 5, distance 42
    .byte $A0, $29
    ; backreference count 3, distance 170
    .byte $80, $A9
    ; backreference count 4, distance 42
    .byte $90, $29
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
