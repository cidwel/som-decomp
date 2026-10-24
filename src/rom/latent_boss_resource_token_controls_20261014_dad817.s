; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D817
boss_lz_controls_dad817:
    ; backreference count 4, distance 16
    .byte $88, $0F
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
