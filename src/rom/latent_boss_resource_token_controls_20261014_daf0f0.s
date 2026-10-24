; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F0F0
boss_lz_controls_daf0f0:
    ; backreference count 3, distance 2296
    .byte $88, $F7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
