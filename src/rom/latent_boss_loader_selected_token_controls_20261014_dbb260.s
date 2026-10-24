; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B260
boss_lz_controls_dbb260:
    ; backreference count 4, distance 423
    .byte $85, $A6
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
