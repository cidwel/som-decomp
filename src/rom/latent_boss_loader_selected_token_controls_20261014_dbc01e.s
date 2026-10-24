; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C01E
boss_lz_controls_dbc01e:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
