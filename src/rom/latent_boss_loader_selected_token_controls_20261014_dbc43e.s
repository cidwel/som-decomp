; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C43E
boss_lz_controls_dbc43e:
    ; backreference count 8, distance 1632
    .byte $AE, $5F
    ; backreference count 5, distance 140
    .byte $90, $8B
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
