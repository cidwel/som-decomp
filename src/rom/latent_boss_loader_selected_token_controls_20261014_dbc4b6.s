; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4B6
boss_lz_controls_dbc4b6:
    ; backreference count 3, distance 461
    .byte $81, $CC
    ; backreference count 6, distance 1260
    .byte $9C, $EB
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
