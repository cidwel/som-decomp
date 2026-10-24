; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F10C
boss_lz_controls_daf10c:
    ; backreference count 3, distance 514
    .byte $82, $01
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
