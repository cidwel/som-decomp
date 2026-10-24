; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB13
boss_lz_controls_dacb13:
    ; backreference count 4, distance 42
    .byte $88, $29
    ; literal count 28; subsequent asset bytes excluded
    .byte $1B
