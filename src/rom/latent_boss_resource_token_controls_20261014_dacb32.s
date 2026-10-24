; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB32
boss_lz_controls_dacb32:
    ; backreference count 4, distance 1206
    .byte $8C, $B5
    ; backreference count 18, distance 514
    .byte $FA, $01
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
