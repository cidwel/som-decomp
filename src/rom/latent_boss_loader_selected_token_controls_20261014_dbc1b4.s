; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1B4
boss_lz_controls_dbc1b4:
    ; backreference count 4, distance 1467
    .byte $8D, $BA
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
