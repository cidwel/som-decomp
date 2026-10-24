; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0648
boss_lz_controls_db0648:
    ; backreference count 3, distance 1412
    .byte $85, $83
    ; backreference count 3, distance 130
    .byte $80, $81
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
