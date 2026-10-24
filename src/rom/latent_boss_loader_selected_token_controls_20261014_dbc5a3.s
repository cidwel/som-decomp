; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C5A3
boss_lz_controls_dbc5a3:
    ; backreference count 3, distance 1505
    .byte $85, $E0
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
