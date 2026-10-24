; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E031
boss_lz_controls_dae031:
    ; backreference count 6, distance 18
    .byte $98, $11
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
