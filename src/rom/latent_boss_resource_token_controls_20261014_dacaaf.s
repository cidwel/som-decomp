; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAAF
boss_lz_controls_dacaaf:
    ; backreference count 4, distance 207
    .byte $88, $CE
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
