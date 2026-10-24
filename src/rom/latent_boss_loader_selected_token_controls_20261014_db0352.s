; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0352
boss_lz_controls_db0352:
    ; backreference count 3, distance 71
    .byte $80, $46
    ; backreference count 4, distance 227
    .byte $90, $E2
    ; backreference count 3, distance 200
    .byte $80, $C7
    ; backreference count 4, distance 363
    .byte $91, $6A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
