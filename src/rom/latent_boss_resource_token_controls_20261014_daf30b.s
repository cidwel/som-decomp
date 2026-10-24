; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F30B
boss_lz_controls_daf30b:
    ; backreference count 4, distance 3474
    .byte $9D, $91
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
