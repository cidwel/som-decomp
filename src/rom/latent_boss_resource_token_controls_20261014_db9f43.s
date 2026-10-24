; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F43
boss_lz_controls_db9f43:
    ; backreference count 3, distance 179
    .byte $80, $B2
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
