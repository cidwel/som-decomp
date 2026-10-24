; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D89F
boss_lz_controls_dad89f:
    ; backreference count 3, distance 681
    .byte $82, $A8
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
