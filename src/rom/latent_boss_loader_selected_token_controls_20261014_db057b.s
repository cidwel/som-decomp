; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $057B
boss_lz_controls_db057b:
    ; backreference count 4, distance 107
    .byte $90, $6A
    ; backreference count 6, distance 801
    .byte $B3, $20
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
