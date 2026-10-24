; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEC8
boss_lz_controls_dacec8:
    ; backreference count 3, distance 171
    .byte $80, $AA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
