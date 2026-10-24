; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0556
boss_lz_controls_db0556:
    ; backreference count 3, distance 393
    .byte $81, $88
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
