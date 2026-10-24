; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA77
boss_lz_controls_daba77:
    ; backreference count 4, distance 468
    .byte $85, $D3
    ; backreference count 5, distance 57
    .byte $88, $38
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
