; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C45E
boss_lz_controls_dbc45e:
    ; backreference count 7, distance 36
    .byte $A0, $23
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
