; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E9B3
boss_lz_controls_dae9b3:
    ; backreference count 4, distance 100
    .byte $90, $63
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
