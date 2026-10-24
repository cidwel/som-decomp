; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C02F
boss_lz_controls_dbc02f:
    ; backreference count 4, distance 418
    .byte $89, $A1
    ; literal count 36; subsequent asset bytes excluded
    .byte $23
