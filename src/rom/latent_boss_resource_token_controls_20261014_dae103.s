; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E103
boss_lz_controls_dae103:
    ; backreference count 4, distance 1520
    .byte $8D, $EF
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
