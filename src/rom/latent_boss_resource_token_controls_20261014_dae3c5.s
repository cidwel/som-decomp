; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E3C5
boss_lz_controls_dae3c5:
    ; backreference count 3, distance 1270
    .byte $84, $F5
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
