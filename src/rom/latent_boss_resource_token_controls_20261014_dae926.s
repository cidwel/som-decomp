; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E926
boss_lz_controls_dae926:
    ; backreference count 9, distance 18
    .byte $E0, $11
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
