; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C29F
boss_lz_controls_dbc29f:
    ; backreference count 3, distance 178
    .byte $80, $B1
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
