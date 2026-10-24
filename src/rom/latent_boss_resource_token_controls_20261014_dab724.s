; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B724
boss_lz_controls_dab724:
    ; backreference count 3, distance 30
    .byte $80, $1D
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
