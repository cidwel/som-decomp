; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B383
boss_lz_controls_dbb383:
    ; backreference count 4, distance 25
    .byte $84, $18
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
