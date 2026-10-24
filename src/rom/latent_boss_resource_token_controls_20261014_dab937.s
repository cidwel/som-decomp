; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B937
boss_lz_controls_dab937:
    ; backreference count 20, distance 444
    .byte $C5, $BB
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
