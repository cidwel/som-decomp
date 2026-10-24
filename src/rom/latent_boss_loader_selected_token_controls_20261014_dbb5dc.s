; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B5DC
boss_lz_controls_dbb5dc:
    ; backreference count 3, distance 554
    .byte $82, $29
    ; literal count 25; subsequent asset bytes excluded
    .byte $18
