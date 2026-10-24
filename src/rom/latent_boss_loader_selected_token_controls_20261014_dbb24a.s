; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B24A
boss_lz_controls_dbb24a:
    ; backreference count 10, distance 369
    .byte $9D, $70
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
