; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B03C
boss_lz_controls_dbb03c:
    ; backreference count 25, distance 582
    .byte $DA, $45
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
