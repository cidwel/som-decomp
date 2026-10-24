; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB48
boss_lz_controls_dacb48:
    ; backreference count 6, distance 514
    .byte $9A, $01
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
