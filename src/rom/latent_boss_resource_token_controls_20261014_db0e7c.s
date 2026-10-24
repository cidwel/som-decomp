; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0E7C
boss_lz_controls_db0e7c:
    ; backreference count 51, distance 249
    .byte $E0, $F8
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 80; subsequent asset bytes excluded
    .byte $4F
