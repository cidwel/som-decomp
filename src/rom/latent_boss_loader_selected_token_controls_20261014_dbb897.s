; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B897
boss_lz_controls_dbb897:
    ; backreference count 3, distance 493
    .byte $81, $EC
    ; literal count 82; subsequent asset bytes excluded
    .byte $51
