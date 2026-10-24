; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0216
boss_lz_controls_db0216:
    ; backreference count 3, distance 97
    .byte $80, $60
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
