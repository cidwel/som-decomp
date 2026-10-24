; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0AD
boss_lz_controls_dac0ad:
    ; backreference count 3, distance 708
    .byte $82, $C3
    ; backreference count 3, distance 546
    .byte $82, $21
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
