; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B70C
boss_lz_controls_dbb70c:
    ; backreference count 4, distance 19
    .byte $84, $12
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
