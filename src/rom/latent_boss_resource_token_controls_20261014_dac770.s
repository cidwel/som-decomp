; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C770
boss_lz_controls_dac770:
    ; backreference count 6, distance 581
    .byte $9A, $44
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
