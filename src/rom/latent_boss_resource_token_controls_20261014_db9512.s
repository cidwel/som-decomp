; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9512
boss_lz_controls_db9512:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; backreference count 3, distance 85
    .byte $80, $54
    ; backreference count 3, distance 1244
    .byte $84, $DB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
