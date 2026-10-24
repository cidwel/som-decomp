; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0347
boss_lz_controls_db0347:
    ; backreference count 3, distance 243
    .byte $80, $F2
    ; backreference count 3, distance 58
    .byte $80, $39
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
