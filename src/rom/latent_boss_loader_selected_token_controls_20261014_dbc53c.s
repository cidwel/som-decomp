; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C53C
boss_lz_controls_dbc53c:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
