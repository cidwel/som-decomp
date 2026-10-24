; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BA3
boss_lz_controls_db0ba3:
    ; backreference count 4, distance 14
    .byte $90, $0D
    ; backreference count 3, distance 22
    .byte $80, $15
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
