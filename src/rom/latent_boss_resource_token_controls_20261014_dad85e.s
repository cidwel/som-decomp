; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D85E
boss_lz_controls_dad85e:
    ; backreference count 3, distance 1522
    .byte $85, $F1
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
