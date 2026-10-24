; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C835
boss_lz_controls_dac835:
    ; backreference count 3, distance 1123
    .byte $84, $62
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
