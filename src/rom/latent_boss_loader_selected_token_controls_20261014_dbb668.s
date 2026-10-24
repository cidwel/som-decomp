; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B668
boss_lz_controls_dbb668:
    ; backreference count 3, distance 759
    .byte $82, $F6
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
