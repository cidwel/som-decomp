; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F104
boss_lz_controls_daf104:
    ; backreference count 7, distance 807
    .byte $C3, $26
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
