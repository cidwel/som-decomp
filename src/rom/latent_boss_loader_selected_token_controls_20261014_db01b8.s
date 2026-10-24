; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01B8
boss_lz_controls_db01b8:
    ; backreference count 3, distance 105
    .byte $80, $68
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; backreference count 3, distance 325
    .byte $81, $44
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
