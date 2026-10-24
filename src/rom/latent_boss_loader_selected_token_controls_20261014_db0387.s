; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0387
boss_lz_controls_db0387:
    ; backreference count 5, distance 893
    .byte $A3, $7C
    ; backreference count 4, distance 34
    .byte $90, $21
    ; backreference count 3, distance 826
    .byte $83, $39
    ; backreference count 3, distance 546
    .byte $82, $21
    ; backreference count 3, distance 652
    .byte $82, $8B
    ; backreference count 4, distance 31
    .byte $90, $1E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
