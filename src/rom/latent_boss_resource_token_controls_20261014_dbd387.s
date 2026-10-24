; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D387
boss_lz_controls_dbd387:
    ; backreference count 3, distance 250
    .byte $80, $F9
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
