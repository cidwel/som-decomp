; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B15E
boss_lz_controls_dbb15e:
    ; backreference count 3, distance 868
    .byte $83, $63
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
