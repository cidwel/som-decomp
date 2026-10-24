; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08D1
boss_lz_controls_db08d1:
    ; backreference count 7, distance 1417
    .byte $C5, $88
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
