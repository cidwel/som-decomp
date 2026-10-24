; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0128
boss_lz_controls_db0128:
    ; backreference count 3, distance 67
    .byte $80, $42
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
