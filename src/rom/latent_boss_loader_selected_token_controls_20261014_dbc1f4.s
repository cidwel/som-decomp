; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1F4
boss_lz_controls_dbc1f4:
    ; backreference count 4, distance 546
    .byte $8A, $21
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
