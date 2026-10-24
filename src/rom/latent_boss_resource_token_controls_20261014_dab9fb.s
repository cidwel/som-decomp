; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9FB
boss_lz_controls_dab9fb:
    ; backreference count 4, distance 190
    .byte $84, $BD
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
