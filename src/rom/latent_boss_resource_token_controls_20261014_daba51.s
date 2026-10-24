; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA51
boss_lz_controls_daba51:
    ; backreference count 5, distance 10
    .byte $88, $09
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
