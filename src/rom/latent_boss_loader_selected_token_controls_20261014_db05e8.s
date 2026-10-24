; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05E8
boss_lz_controls_db05e8:
    ; backreference count 4, distance 389
    .byte $91, $84
    ; backreference count 5, distance 1555
    .byte $A6, $12
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
