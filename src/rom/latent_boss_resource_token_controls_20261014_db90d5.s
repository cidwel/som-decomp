; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $90D5
boss_lz_controls_db90d5:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 38; subsequent asset bytes excluded
    .byte $25
