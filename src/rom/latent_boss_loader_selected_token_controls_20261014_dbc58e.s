; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C58E
boss_lz_controls_dbc58e:
    ; backreference count 11, distance 43
    .byte $C0, $2A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
